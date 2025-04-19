#include <iostream>
#include <vector>

using namespace std;

// Waveband Sequence
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<long long> dp(101);
	dp[1] = 1; dp[2] = 1; dp[3] = 1;
	for (int i = 4; i < 101; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}