#include <iostream>
#include <vector>

using namespace std;

// Number of easy stairs
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(10));
	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n ; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][0] = dp[i - 1][j + 1];
			}
			else if (j == 9)
			{
				dp[i][9] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}

			dp[i][j] %= 1000000000;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += dp[n][i];
		ans %= 1000000000;
	}

	cout << ans;

	return 0;
}