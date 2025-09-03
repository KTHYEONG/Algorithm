#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> v;
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 1;
	while (true) {
		cin >> n;

		if (n == 0) {
			break;
		}

		v.assign(n + 1, vector<int>(4));

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				cin >> v[i][j];
			}
		}

		dp.assign(n + 1, vector<int>(4));
		dp[1][1] = INT_MAX;
		dp[1][2] = v[1][2];
		dp[1][3] = v[1][2] + v[1][3];
		for (int i = 2; i <= n; i++)
		{
			dp[i][1] = v[i][1] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][2] = v[i][2] + min({ dp[i][1], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3] });
			dp[i][3] = v[i][3] + min({ dp[i][2], dp[i - 1][2], dp[i - 1][3] });
		}

		cout << cnt++ << ". " << dp[n][2] << '\n';
	}


	return 0;
}