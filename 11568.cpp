#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> dp;

// Min-gyun's scheme
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n + 1);
	dp.resize(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	
	int ans = 0;
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
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}