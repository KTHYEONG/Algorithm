#include <iostream>
#include <vector>

using namespace std;

// Guitarist
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s, m;
	cin >> n >> s >> m;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	vector<int> volume(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> volume[i];
	}

	dp[0][s] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j] == 1)
			{
				if (j + volume[i] <= m)
				{
					dp[i][j + volume[i]] = 1;
				}

				if (j - volume[i] >= 0)
				{
					dp[i][j - volume[i]] = 1;
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= m; i++)
	{
		if (dp[n][i] == 1)
		{
			ans = max(ans, i);
		}
	}
	
	cout << ans;

	return 0;
}