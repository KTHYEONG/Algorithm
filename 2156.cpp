#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Wine tasting
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

	vector<int> dp(n + 1);
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	for (int i = 3; i <= n; i++)
	{
		int a = dp[i - 3] + v[i - 1] + v[i];
		int b = dp[i - 2] + v[i];
		int c = dp[i - 1];
		dp[i] = max(a, max(b, c));
	}

	cout << dp[n];

	return 0;
}