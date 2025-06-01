#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Longest decreasing subsequence
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	vector<int> dp(n + 1, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[i] < A[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}