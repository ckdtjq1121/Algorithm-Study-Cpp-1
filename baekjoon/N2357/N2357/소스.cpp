#include <vector>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cmath>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-06
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation. (mmap ver.)
 */
constexpr int SZ = 1 << 15;

class INPUT {
private:
	char* p;
public:
	INPUT() {
		struct stat st; fstat(0, &st);
		p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
	}
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() { return *p++; }
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		return flag ? -ret : ret;
	}
} cin;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	void Flush() {
		write(1, write_buf, write_idx);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
} cout;
/////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 100001;
const int INF = 2147483647;

int arr[MAX];
vector<pair<int, int> > tree(4 * MAX);

pair<int, int> init(int node, int start, int end)
{
	if (start == end)
		return tree[node] = make_pair(arr[start], arr[end]);

	int mid = (start + end) / 2;
	pair<int, int> leftNode = init(2 * node, start, mid);
	pair<int, int> rightNode = init(2 * node + 1, mid + 1, end);
	return tree[node] = make_pair(min(leftNode.first, rightNode.first), max(leftNode.second, rightNode.second));
}

pair<int, int> query(int node, int start, int end, int left, int right)
{
	if (end < left || right < start)
		return make_pair(INF, -INF);

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	pair<int, int> leftNode = query(2 * node, start, mid, left, right);
	pair<int, int> rightNode = query(2 * node + 1, mid + 1, end, left, right);
	return make_pair(min(leftNode.first, rightNode.first), max(leftNode.second, rightNode.second));
}
int main()
{
	int n = cin.ReadInt<int>(), m = cin.ReadInt<int>();

	for (int i = 1; i <= n; i++)
	{
		arr[i] = cin.ReadInt<int>();
	}

	init(1, 1, n);

	for (int i = 0; i < m; i++)
	{
		int a = cin.ReadInt<int>(), b = cin.ReadInt<int>();
		
		pair<int, int> ans = query(1, 1, n, a, b);
		cout.WriteInt<int>(ans.first), cout.WriteChar(' ');
        cout.WriteInt<int>(ans.second), cout.WriteChar('\n');
	}
}
// cin이 scanf보다 빠르다
// cout이 printf보다 느리다