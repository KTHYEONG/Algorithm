#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
long long dp[10001];

// Fibonacci
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 1; i <= t; i++)
	{
		int p, q;
		cin >> p >> q;
		for (int j = 3; j <= p; j++)
		{
			dp[j] = (dp[j - 1] + dp[j - 2]) % q;
		}

		cout << "Case #" << i << ": " << dp[p] % q << '\n';
	}

	return 0;
}