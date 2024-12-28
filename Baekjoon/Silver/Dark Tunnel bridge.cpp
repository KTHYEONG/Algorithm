#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<int> x(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> x[i];
    }

    // 가로등 간의 간격
    int maxGap = 0;
    for (int i = 1; i < m; i++)
    {
        maxGap = max(maxGap, x[i] - x[i - 1]);
    }

    // 처음과 마지막부터의 가로등 간격
    int startGap = x[0];
    int endGap = n - x[m - 1];

    int ans = max({(maxGap + 1) / 2, startGap, endGap});

    cout << ans;

    return 0;
}