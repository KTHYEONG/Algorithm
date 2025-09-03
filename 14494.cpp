#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int dp[1001][1001];

// What is the dynamic?
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = (dp[i - 1][j] + (dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007) % 1000000007;
		}
	}

	cout << dp[n][m];

	return 0;
}