#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k;
    cin >> k;

    vector<vector<int>> dp(k + 1, vector<int>(3, 0));
    dp[1][2] = 1;
    for (int i = 2; i <= k; i++)
    {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][2];
    }

    cout << dp[k][1] << " " << dp[k][2];

    return 0;
}