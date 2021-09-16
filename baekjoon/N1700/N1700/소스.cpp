#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<queue<int> > next(k + 1);
	vector<int> arr(k + 1);
	for (int i = 1; i <= k; i++)
	{
		cin >> arr[i];

		next[arr[i]].push(i);
	}

	int ans = 0;
	vector<bool> plug(k + 1, false);
	int p_size = 0;
	for (int i = 1; i <= k; i++)
	{
		int num = arr[i];
		if (!plug[num])
		{
			if (p_size < n)
			{
				plug[num] = true;
				p_size++;
			}
			else
			{
				// find min
				int maxIdx = 0;
				int max = 0;
				for (int i = 1; i <= k; i++)
				{
					if (plug[i])
					{
						if (next[i].empty()) // there is not next - > unplug
						{
							maxIdx = i;
							break;
						}
						else if (max < next[i].front()) // last entry -> unplug
						{
							maxIdx = i;
							max = next[i].front();
						}
					}
				}

				// unplug one
				plug[maxIdx] = false;

				// plug[arr[i]]
				plug[num] = true;

				// ans++;
				ans++;
			}
		}
		if (!next[num].empty())
			next[num].pop();
	}

	cout << ans << "\n";
}