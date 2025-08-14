#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int v[10][10];
int dp[7][7][3];

// Jinwoo's Trip to the Moon
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];

			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = v[i][j];
			if (j == 0)
			{
				dp[i][j][0] = INT_MAX;
			}
			if (j == m - 1)
			{
				dp[i][j][2] = INT_MAX;
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j != 0)
			{
				dp[i][j][0] += min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]);
			}

			dp[i][j][1] += min(dp[i - 1][j][0], dp[i - 1][j][2]);

			if (j != m - 1)
			{
				dp[i][j][2] += min(dp[i - 1][j + 1][0], dp[i - 1][j + 1][1]);
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ans = min(ans, dp[n - 1][i][j]);
		}
	}

	cout << ans;

	return 0;
}