#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<int>> dp;

// Resource gathering
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	v.resize(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> v[i][j];
		}
	}

	dp.resize(n + 1, vector<int>(m + 1));
	dp[1][1] = v[1][1];
	for (int i = 2; i <= m; i++)
	{
		if (v[1][i] == 0)
		{
			dp[1][i] = dp[1][i - 1];
		}
		else
		{
			dp[1][i] = dp[1][i - 1] + 1;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (v[i][1] == 0)
		{
			dp[i][1] = dp[i - 1][1];
		}
		else
		{
			dp[i][1] = dp[i - 1][1] + 1;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= m; j++)
		{
			if (v[i][j] == 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
			}
		}
	}

	cout << dp[n][m];

	return 0;
}