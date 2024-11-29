#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i] == INT_MAX)
            continue;

        for (int j = 1; j <= v[i] && i + j <= n; j++)
        {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    if (dp[n] == INT_MAX)
        cout << -1;
    else
        cout << dp[n];

    return 0;
}