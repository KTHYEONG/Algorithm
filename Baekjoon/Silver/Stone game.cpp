#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0)
            dp[i] = 1;
        else
            dp[i] = 0;
    }

    if (dp[n] == 0)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}