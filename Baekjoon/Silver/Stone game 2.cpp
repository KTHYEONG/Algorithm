#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= n; i++)
    {
        if (dp[i - 1] == 0 || dp[i - 3] == 0)
            dp[i] = 1;
        else
            dp[i] = 0;
    }

    if (dp[n] == 0)
        cout << "CY";
    else
        cout << "SK";

    return 0;
}