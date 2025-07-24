#include <iostream>
#include <vector>

using namespace std;

// Add 1, 2, 3 4
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<vector<int>> dp(10001, vector<int>(4));
	dp[0][1] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 10000; i++)
	{
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		if (i >= 3)
		{
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		}
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}

	return 0;
}