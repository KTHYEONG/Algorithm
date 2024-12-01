#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> hpArr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> hpArr[i];
    }

    vector<int> happy(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> happy[i];
    }

    vector<int> dp(101, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 100; j >= hpArr[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - hpArr[i]] + happy[i]);
        }
    }

    cout << dp[99];

    return 0;
}