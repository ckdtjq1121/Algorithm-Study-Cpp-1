// ����� ������ �̿��ؼ� Ʈ���� ���� �� �ִ�.
// Ʈ������ N1 -> N2 �� �ִ� �Ÿ��� ���Ѵ�.
#include<bits/stdc++.h>
int n;
int longest;

using namespace std;

const int MAX = 100;

struct TreeNode
{
    vector<TreeNode*> children;
};

int N, y[MAX], x[MAX], radius[MAX];
//���ݱ��� ã�� ���� �� leaf~leaf ����� ���̸� ����

//root�� ��Ʈ�� �ϴ� ����Ʈ���� ���̸� ��ȯ
int height(TreeNode* root)
{

    //�� �ڽ��� ��Ʈ�� �ϴ� ����Ʈ���� ���̸� ����Ѵ�
    vector<int> heights;
    for (int i = 0; i < root->children.size(); i++)
        heights.push_back(height(root->children[i]));

    //���� �ڽ��� �ϳ��� ���ٸ� 0�� ��ȯ�Ѵ�
    if (heights.empty())
        return 0;

    sort(heights.begin(), heights.end());

    //root�� �ֻ��� ���� �ϴ� ��θ� �������
    if (heights.size() >= 2)
        longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);

    //Ʈ���� ���̴� ����Ʈ�� ������ �ִ�ġ�� 1�� ���� ���
    return heights.back() + 1;

}

//�� ��� ������ ���� �� ����� ���̸� ���

int solve(TreeNode* root)
{
    longest = 0;
    //Ʈ���� ���̿� �ִ� leaf~leaf ��� ���� �� ū ���� ����
    int h = height(root);
    return max(longest, h);

}

int sqr(int x) //x * x ��ȯ
{
    return x * x;
}



//�� ���� a, b�� �߽��� ���� �Ÿ��� ���� ��ȯ
int sqrdist(int a, int b)
{
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}



//���� a�� ���� b�� �����ϴ��� Ȯ��

bool encloses(int a, int b)
{
    return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}



//���� Ʈ������ parent�� child�� �θ����� Ȯ��

//parent�� child�� �� ���� �����ؾ� �Ѵ�

bool isChild(int parent, int child)
{
  if (!encloses(parent, child))
        return false;

    for (int i = 0; i < N; i++)
        if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
            return false;

    return true;
}

//root ������ ��Ʈ�� �ϴ� Ʈ���� ����
TreeNode* getTree(int root)
{
    TreeNode* result = new TreeNode();

    for (int ch = 0; ch < N; ch++)
        //ch ������ root ������ ���������� ���ԵǾ� �ִٸ�
        //Ʈ���� ����� �ڼ� ��Ͽ� �߰��Ѵ�

        if (isChild(root, ch))
            result->children.push_back(getTree(ch));

    return result;

}


int main(void)
{
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> x[i] >> y[i] >> radius[i];

        TreeNode* T = getTree(0);
        cout << solve(T) << endl;

    }

    return 0;

}
