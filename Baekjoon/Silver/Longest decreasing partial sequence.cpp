#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (v[i] < v[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    sort(dp.begin(), dp.end());

    cout << dp[n];

    return 0;
}