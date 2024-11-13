#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<vector<int>> v(2, vector<int>(n + 1, 0));
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        for (int j = 0; j < 2; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                cin >> v[j][k];
            }
        }

        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[0][1] = v[0][1];
        dp[1][1] = v[1][1];
        for (int j = 2; j <= n; j++)
        {
            dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + v[0][j];
            dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + v[1][j];
        }

        cout << max(dp[0][n], dp[1][n]) << endl;
    }

    return 0;
}