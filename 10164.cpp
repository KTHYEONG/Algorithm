#include <iostream>
#include <vector>

using namespace std;

// Path of grid
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> dp(16, vector<int>(16));
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] += dp[i][j - 1] + dp[i - 1][j];
		}
	}

	int x, y;
	if (k != 0)
	{
		if (k % m != 0)
		{
			y = k % m;
			x = (k - y) / m + 1;
		}
		else
		{
			x = k / m;
			y = m;
		}
	}

	if (k == 0)
	{
		cout << dp[n][m];
	}
	else
	{
		cout << dp[x][y] * dp[n - x + 1][m - y + 1];
	}
	return 0;
}