#include <iostream>
#include <vector>

using namespace std;

// RGB street
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(1001);
	vector<vector<int>> dp(1001, vector<int>(3));
	for (int i = 1; i <= n; i++)
	{
		cin >> v[0] >> v[1] >> v[2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + v[2];
	}

	cout << min(dp[n][0], min(dp[n][1], dp[n][2]));

	return 0;
}