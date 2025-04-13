#include <iostream>
#include <vector>

using namespace std;

// Climbing stairs
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int stairNum;
	cin >> stairNum;

	vector<int> v(stairNum + 1);
	vector<int> dp(stairNum + 1);
	for (int i = 1; i <= stairNum; i++)
	{
		cin >> v[i];
	}

	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	dp[3] = max(v[2] + v[3], v[1] + v[3]);
	for (int i = 4; i <= stairNum; i++)
	{
		dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
	}

	cout << dp[stairNum];
	
	return 0;
}