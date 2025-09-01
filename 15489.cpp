#include <iostream>
#include <algorithm>

using namespace std;

int r, c, w;
int dp[31][31];

// Pascal's Triangle
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> w;

	for (int i = 1; i <= 30; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || j == i)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			ans += dp[r + i][c + j];
		}
	}

	cout << ans;

	return 0;
}