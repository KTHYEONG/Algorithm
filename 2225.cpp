#include <iostream>
#include <vector>

using namespace std;

// SumDecomposition
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> dp(201, vector<int> (201));
	for (int i = 0; i <= k; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}

	cout << dp[n][k];

	return 0;
}