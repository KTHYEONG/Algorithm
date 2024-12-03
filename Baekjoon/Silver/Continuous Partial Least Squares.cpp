#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<double> v(n + 1, 0.0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<double> dp(n + 1, 0.0);
    dp[1] = v[1];
    double ans = dp[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(v[i], v[i] * dp[i - 1]);
        ans = max(ans, dp[i]);
    }

    cout << fixed, cout.precision(3);
    cout << ans;

    return 0;
}