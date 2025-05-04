#include <iostream>

using namespace std;

// Stone Game
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n % 2 != 0)
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}

	return 0;
}

// dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);