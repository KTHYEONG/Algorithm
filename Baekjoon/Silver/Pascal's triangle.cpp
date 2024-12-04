#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for (int i = 3; i <= n; i++)
    {
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n][k];

    return 0;
}