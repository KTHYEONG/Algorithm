#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Continuous sum
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> dp(n);
	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;

		if (i == 0)
		{
			dp[0] = num;
			continue;
		}

		dp[i] = max(dp[i - 1] + num, num);
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}