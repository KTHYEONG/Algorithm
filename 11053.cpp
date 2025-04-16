#include <iostream>
#include <vector>

using namespace std;

// Longest incrementing sequence
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	vector<int> dp(1001);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(dp[i], ans);
	}

	cout << ans;

	return 0;
}