#include <iostream>
#include <vector>

using namespace std;

// Coin
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<int> coins(n + 1);
		for (int i = 1; i <= n; i++)
		{
			cin >> coins[i];
		}

		int m;
		cin >> m;

		vector<int> dp(m + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = coins[i]; j <= m; j++)
			{
				dp[j] += dp[j - coins[i]];
			}
		}

		cout << dp[m] << '\n';
	}

	return 0;
}