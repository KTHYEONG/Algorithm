#include <iostream>
#include <vector>

using namespace std;

// 01 Tile
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> dp(n + 1);
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}

	cout << dp[n];

	return 0;
}