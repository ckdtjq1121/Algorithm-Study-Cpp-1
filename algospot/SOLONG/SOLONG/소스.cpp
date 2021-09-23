#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

const int ALPHABETS = 26;

int toNumber(char ch)
{
	return ch - 'A';
}

struct TrieNode {
	TrieNode* children[ALPHABETS];

	int terminal;
	int first;
	TrieNode() : terminal(-1), first(-1)
	{
		memset(children, 0, sizeof(children));
	}
	~TrieNode()
	{
		for (int i = 0; i < ALPHABETS; i++)
			if (children[i])
				delete children[i];
	}

	// trie�� ���ڿ� �ֱ�
	void insert(const char* key, int id)
	{
		if (first == -1)
			first = id;

		if (*key == 0)
			terminal = true;
		else
		{
			int next = toNumber(*key);

			if (children[next] == NULL)
				children[next] = new TrieNode();

			children[next]->insert(key + 1, id);
		}
	}

	// trie�� ���ڿ� �ִ��� ã�� - ã���� != NULL / �� ã���� == NULL
	TrieNode* find(const char* key)
	{
		if (*key == 0) 
			return this;

		int next = toNumber(*key);
		if (children[next] == NULL)
			return NULL;

		return children[next]->find(key + 1);
	}

	// key���� Ÿ���� Ƚ��
	int type(const char* key, int id)
	{
		if (*key == 0)
			return 0;
		if (first == id)
			return 1;

		int next = toNumber(*key);
		return 1 + children[next]->type(key + 1, id);
	}


};

// word type Ƚ��
int countKeys(TrieNode* trie, const char* word)
{
	TrieNode* node = trie->find(word);

	if (node == NULL || node->terminal == -1)
		return strlen(word);

	return trie->type(word, node->terminal);
}

TrieNode* readInput(int words)
{
	vector<pair<int, string> > input;
	for (int i = 0; i < words; i++)
	{
		char buf[11]; // ���ڿ��� �ִ� ���� 10
		int freq;
		cin >> buf >> freq;
		input.push_back(make_pair(-freq, buf));	// �������� ������ ���ؼ�
	}
	sort(input.begin(), input.end()); // �������� ����

	TrieNode* trie = new TrieNode();
	for (int i = 0; i < input.size(); i++)
		trie->insert(input[i].second.c_str(), i);

	trie->first = -1;
	return trie;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, m;
		cin >> n >> m;


		TrieNode *trie = readInput(n);
		int result = 0;
		for (int i = 0; i < m; i++)
		{
			char buf[11];
			cin >> buf;
			result += countKeys(trie, buf);
		}

		cout << result << "\n";

	}
}