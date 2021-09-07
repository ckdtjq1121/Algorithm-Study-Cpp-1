// 요새의 정보를 이용해서 트리를 만들 수 있다.
// 트리에서 N1 -> N2 의 최대 거리를 구한다.
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
//지금까지 찾은 가장 긴 leaf~leaf 경로의 길이를 저장

//root를 루트로 하는 서브트리의 높이를 반환
int height(TreeNode* root)
{

    //각 자식을 루트로 하는 서브트리의 높이를 계산한다
    vector<int> heights;
    for (int i = 0; i < root->children.size(); i++)
        heights.push_back(height(root->children[i]));

    //만약 자식이 하나도 없다면 0을 반환한다
    if (heights.empty())
        return 0;

    sort(heights.begin(), heights.end());

    //root를 최상위 노드로 하는 경로를 고려하자
    if (heights.size() >= 2)
        longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);

    //트리의 높이는 서브트리 높이의 최대치에 1을 더해 계산
    return heights.back() + 1;

}

//두 노드 사이의 가장 긴 경로의 길이를 계산

int solve(TreeNode* root)
{
    longest = 0;
    //트리의 높이와 최대 leaf~leaf 경로 길이 중 큰 것을 선택
    int h = height(root);
    return max(longest, h);

}

int sqr(int x) //x * x 반환
{
    return x * x;
}



//두 성벽 a, b의 중심점 간의 거리의 제곱 반환
int sqrdist(int a, int b)
{
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}



//성벽 a가 성벽 b를 포함하는지 확인

bool encloses(int a, int b)
{
    return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}



//성벽 트리에서 parent가 child의 부모인지 확인

//parent는 child를 꼭 직접 포함해야 한다

bool isChild(int parent, int child)
{
  if (!encloses(parent, child))
        return false;

    for (int i = 0; i < N; i++)
        if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
            return false;

    return true;
}

//root 성벽을 루트로 하는 트리를 생성
TreeNode* getTree(int root)
{
    TreeNode* result = new TreeNode();

    for (int ch = 0; ch < N; ch++)
        //ch 성벽이 root 성벽에 직접적으로 포함되어 있다면
        //트리를 만들고 자손 목록에 추가한다

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
