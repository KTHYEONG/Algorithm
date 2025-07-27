#include <iostream>
#include <vector>

using namespace std;

// Generations of Tribbles
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<long long> dp(68);
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 68; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	}

	while (t--)
	{
		int n;
		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}