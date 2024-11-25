#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dp(10001, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = v[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - v[i]];
        }
    }

    cout << dp[k];

    return 0;
}