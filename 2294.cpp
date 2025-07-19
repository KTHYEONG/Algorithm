#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Coin 2
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> dp(k + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= k; j++)
		{
			if (dp[j - v[i]] != INT_MAX)
			{
				dp[j] = min(dp[j], dp[j - v[i]] + 1);
			}
		}
	}

	if (dp[k] == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << dp[k];
	}
	
	return 0;
}