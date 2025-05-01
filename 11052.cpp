#include <iostream>
#include <vector>

using namespace std;

// Buying Card
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		cin >> v[i];
	}

	vector<int> dp(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + v[j]);
		}
	}

	cout << dp[n];

	return 0;
}