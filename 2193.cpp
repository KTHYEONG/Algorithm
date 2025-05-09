#include <iostream>
#include <vector>

using namespace std;

// Pinary number
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> dp(n + 1);
	dp[1] = 1; dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}

