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
        dp[i] = v[i];
        for (int j = 1; j < i; j++)
        {
            // 증가하는 포인트
            if (v[i] > v[j])
                dp[i] = max(dp[i], dp[j] + v[i]);
        }
    }

    sort(dp.begin(), dp.end());

    cout << dp[n];

    return 0;
}