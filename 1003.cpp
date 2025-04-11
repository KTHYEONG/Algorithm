#include <iostream>
#include <vector>

using namespace std;

// Fibonacci function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<pair<int, int>> dp(41);
	dp[0] = make_pair(1, 0);
	dp[1] = make_pair(0, 1);
	for (int i = 2; i < 41; i++)
	{
		dp[i].first = dp[i - 2].first + dp[i - 1].first;
		dp[i].second = dp[i - 2].second + dp[i - 1].second;
	}
	while (t--)
	{
		int n;
		cin >> n;

		cout << dp[n].first << ' ' << dp[n].second << '\n';
	}

	return 0;
}