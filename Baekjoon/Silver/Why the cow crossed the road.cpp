#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> v(b, 0);
    for (int i = 0; i < b; i++)
        cin >> v[i];

    int cnt = 0;
    for (int i = 1; i <= k; i++)
    {
        if (find(v.begin(), v.end(), i) != v.end())
            cnt++;
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n - k; i++)
    {
        if (find(v.begin(), v.end(), i) != v.end())
            cnt--;

        if (find(v.begin(), v.end(), i + k) != v.end())
            cnt++;

        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}