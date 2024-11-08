#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> v(n, {0, 0});
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (i + v[i].first <= n)
            dp[i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);

        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n];

    return 0;
}