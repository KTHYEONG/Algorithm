#include <vector>
#include <iostream>

using namespace std;

// Handshake
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < n + 1; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10;
	}

	cout << dp[n];

	return 0;
}