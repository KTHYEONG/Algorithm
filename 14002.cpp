#include <iostream>
#include <vector>

using namespace std;

// Longest increasing subsequence 4
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	vector<int> list[1001];
	vector<int> dp(n + 1);
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		list[i].push_back(v[i]);
		for (int j = 1; j <= i; j++)
		{
			if (v[i] > v[j])
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					list[i].clear();
					list[i] = list[j];
					list[i].push_back(v[i]);
				}
			}
		}

		if (ans.size() < list[i].size())
		{
			ans = list[i];
		}
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}