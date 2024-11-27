#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, w;
    cin >> t >> w;

    vector<int> v(t + 1, 0);
    for (int i = 1; i <= t; i++)
    {
        cin >> v[i];
    }

    vector<vector<int>> dp(w + 1, vector<int>(3, 0));

    // 초기값 설정
    dp[0][1] = (v[1] == 1) ? 1 : 0; // 1번 나무에서 시작
    if (w > 0)
        dp[1][2] = (v[1] == 2) ? 1 : 0; // 이동하여 2번 나무로 시작

    for (int i = 2; i <= t; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            // 1번 나무에 있을 때
            dp[j][1] = dp[j][1] + (v[i] == 1);
            if (j > 0)
                dp[j][1] = max(dp[j][1], dp[j - 1][2] + (v[i] == 1));

            // 2번 나무에 있을 때
            dp[j][2] = dp[j][2] + (v[i] == 2);
            if (j > 0)
                dp[j][2] = max(dp[j][2], dp[j - 1][1] + (v[i] == 2));
        }
    }

    // 최댓값 계산
    int ans = 0;
    for (int j = 0; j <= w; j++)
    {
        ans = max({ans, dp[j][1], dp[j][2]});
    }

    cout << ans << endl;

    return 0;
}
