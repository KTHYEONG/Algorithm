#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Deploy soldiers
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> soldier(n);
	for (int i = 0; i < n; i++)
	{
		cin >> soldier[i];
	}

	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (soldier[i] < soldier[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maxLen = *max_element(dp.begin(), dp.end());
	cout << n - maxLen;

	return 0;
}