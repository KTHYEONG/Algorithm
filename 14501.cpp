#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Leaving the company
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> t(n + 1), p(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	vector<int> dp(n + 2);
	for (int i = 1; i <= n; i++)
	{
		dp[i + 1] = max(dp[i + 1], dp[i]);

		if (i + t[i] <= n + 1)
		{
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}