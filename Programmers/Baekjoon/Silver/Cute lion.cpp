#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == 1)
            v.push_back(i);
    }

    if (v.size() < k)
    {
        cout << -1;
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 0; i <= v.size() - k; i++)
    {
        ans = min(ans, v[i + k - 1] - v[i] + 1);
    }

    cout << ans;

    return 0;
}