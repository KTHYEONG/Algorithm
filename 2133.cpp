#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[31];

// Filling Tile
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2)
	{
		// �Ϲ����� ����� ���
		dp[i] = dp[i - 2] * dp[2];

		// Ư���� ����� ���
		for (int j = i - 4; j >= 0; j -= 2)
		{
			dp[i] = dp[i] + (dp[j] * 2);
		}
	}

	cout << dp[n];

	return 0;
}