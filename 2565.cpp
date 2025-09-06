#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[101];

// Electric wire
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<pair<int, int>> line(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> line[i].first >> line[i].second;
	}

	sort(line.begin(), line.end());

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (line[i].second > line[j].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << n - ans;

	return 0;
}