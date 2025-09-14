#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000;

using namespace std;

string code;
int dp[5001];

// Secret code
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> code;

	dp[0] = 1;
	dp[1] = 1;

	if (code[0] == '0')
	{
		cout << 0;
		return 0;
	}

	for (int i = 2; i <= code.length(); i++)
	{
		if (code[i - 1] != '0')
		{
			dp[i] = dp[i - 1] % MOD;
		}

		int temp = (code[i - 2] - '0') * 10 + (code[i - 1] - '0');
		if (temp >= 10 && temp <= 26)
		{
			dp[i] = (dp[i] + dp[i - 2]) % MOD;
		}
	}

	cout << dp[code.length()];

	return 0;
}