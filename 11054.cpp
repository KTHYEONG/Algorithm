#include <iostream>
#include <vector>

using namespace std;

// Longest Bytonic subsequence
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	vector<int> dp1(n + 1);
	for (int i = 1; i <= n; i++)
	{
		dp1[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (v[j] < v[i])
			{
				dp1[i] = max(dp1[j] + 1, dp1[i]);
			}
		}
	}

	vector<int> dp2(n + 1);
	for (int i = n; i >= 1; i--)
	{
		dp2[i] = 1;
		for (int j = n; j >= i; j--)
		{
			if (v[i] > v[j])
			{
				dp2[i] = max(dp2[j] + 1, dp2[i]);
			}
		}
	}

	vector<int> ans(n + 1);
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		ans[i] = dp1[i] + dp2[i];
		res = max(res, ans[i]);
	}

	cout << res - 1;

	return 0;
}