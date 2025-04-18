#include <iostream>
#include <vector>

using namespace std;

// Laying bridge
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<vector<int>> dp(31, vector<int>(31));
	for (int i = 1; i < 31; i++)
	{
		dp[i][0] = dp[i][i] = 1;
	}

	for (int i = 1; i < 31; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;

		cout << dp[m][n] << '\n';
	}

	return 0;
}