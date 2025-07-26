#include <iostream>
#include <vector>

using namespace std;

// Recurrence relation
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}

	cout << dp[n];

	return 0;
}