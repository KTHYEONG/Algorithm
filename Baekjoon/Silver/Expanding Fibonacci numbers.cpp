#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int check = 1;
    if (n < 0)
    {
        n = abs(n);
        if (n % 2 == 0)
            check = -1;
    }

    if (n == 0)
        check = 0;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
    }

    cout << check << endl
         << dp[n];

    return 0;
}