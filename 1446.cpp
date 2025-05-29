#include <iostream>
#include <vector>

using namespace std;

// Shortcut
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, d;
	cin >> n >> d;

	vector<pair<int, int>> v[10001];
	for (int i = 0; i < n; i++)
	{
		int start, goal, length;
		cin >> start >> goal >> length;
		v[goal].push_back({ start, length });
	}

	vector<int> dp(d + 1, 10001);
	dp[0] = 0;
	for (int i = 1; i <= d; i++)
	{
		if (v[i].size() == 0)
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			for (auto element : v[i])
			{
				dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[element.first] + element.second));
			}
		}
	}

	cout << dp[d];

	return 0;
}