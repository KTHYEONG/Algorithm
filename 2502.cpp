#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, k;
int dp[31][2];

// Tiger Eating Rice Cakes
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> d >> k;

	dp[1][0] = 1; dp[1][1] = 0;
	dp[2][0] = 0; dp[2][1] = 1;
	for (int i = 3; i < 31; i++)
	{
		dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
		dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
	}

	// a, b 계수
	long long aCoef = dp[d][0];
	long long bCoef = dp[d][1];

	for (long long a = 1; a * aCoef < k; a++)
	{
		// rem -> b가 담당해야하는 부분
		long long rem = k - a * aCoef;
		if (rem % bCoef == 0)
		{
			long long b = rem / bCoef;
			cout << a << '\n' << b;
			return 0;
		}
	}

	return 0;
}