#include <iostream>
#include <vector>

using namespace std;

// Number of ascents
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> dp(n + 1, vector<int>(10));
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				dp[i][0] = 1;
				continue;
			}

			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 10007;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result = (result + dp[n][i]) % 10007;
	}

	cout << result;

	return 0;
}