#include <iostream>
#include <vector>

using namespace std;

// Ordinary backpack
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> w(n + 1);
	vector<int> v(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j < w[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << dp[n][k];

	return 0;
}