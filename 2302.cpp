#include <iostream>
#include <vector>

using namespace std;

// Theater seats
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int m; 
	cin >> m;

	vector<int> vips(m);
	for (int i = 0; i < m; i++)
	{
		cin >> vips[i];
	}
	
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < n + 1; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	int start = 0, end = 0;
	int ans = 1;
	for (int i = 0; i < m; i++)
	{
		end = vips[i];
		ans *= dp[end - start - 1];
		start = end;
	}
	ans *= dp[n - start];

	cout << ans;

	return 0;
}