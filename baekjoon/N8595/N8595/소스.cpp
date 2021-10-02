#include<bits/stdc++.h>

using namespace std; 
typedef long long ll;
char str[5000001]; // 배열의 크기가 크면 전역 변수로 써야 된다

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cin >> str;

    ll sum = 0;
    string tmp = "";
    for (int i = 0; i < n; i++)
    {
    
        if ('0' <= str[i] && str[i] <= '9')
            tmp += str[i];
        else if (tmp != "")
        {
            sum += stol(tmp);
            tmp = "";
        }
    }
    if (tmp != "")
        sum += stol(tmp);

    cout << sum << "\n";
}