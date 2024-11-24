#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 0 || (i == n - 1 && j == n - 1))
                continue;

            int cur = v[i][j];
            int down = cur + i;
            int right = cur + j;

            if (down < n)
                dp[down][j] += dp[i][j];
            if (right < n)
                dp[i][right] += dp[i][j];
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}