#include <iostream>
#include <vector>

using namespace std;

// Sticker
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<vector<int>> v(2, vector<int>(n + 1));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> v[i][j];
			}
		}

		vector<vector<int>> dp(2, vector<int>(n + 1));
		dp[0][0] = 0; dp[1][0] = 0;
		dp[0][1] = v[0][1]; dp[1][1] = v[1][1];
		for (int i = 2; i < n + 1; i++)
		{
			dp[0][i] = v[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
			dp[1][i] = v[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}

	return 0;
}