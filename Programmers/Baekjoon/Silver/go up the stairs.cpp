#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int stairNum = 0;
    cin >> stairNum;

    vector<int> v(stairNum);
    for (int i = 0; i < stairNum; i++)
        cin >> v[i];

    vector<int> dp(stairNum, 0);
    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max(v[0] + v[2], v[1] + v[2]);
    for (int i = 3; i < stairNum; i++)
        dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i - 2] + v[i]);

    cout << dp[stairNum - 1];

    return 0;
}