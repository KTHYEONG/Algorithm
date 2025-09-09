#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<long long> dp;
vector<char> street;

// BOJ street
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	street.resize(n + 1);
	dp.assign(n + 1, INT_MAX);

	for (int i = 1; i <= n; i++)
	{
		cin >> street[i];
	}
	
	dp[1] = 0;
	for (int i = 1; i < n; i++)
	{
		if (street[i] == 'B')
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (street[j] == 'O')
				{
					dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
				}
			}
		}
		else if (street[i] == 'O')
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (street[j] == 'J')
				{
					dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
				}
			}
		}
		else
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (street[j] == 'B')
				{
					dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
				}
			}
		}
	}

	if (dp[n] == INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << dp[n];
	}

	return 0;
}