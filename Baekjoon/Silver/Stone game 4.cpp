#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[2] = dp[4] = dp[5] = 1;
    for (int i = 6; i <= n; i++)
    {
        if (dp[i - 1] == 1 && dp[i - 3] == 1 && dp[i - 4] == 1)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = 1;
        }
    }

    string ans = "SK";
    if (dp[n] == 0)
        ans = "CY";

    cout << ans;

    return 0;
}