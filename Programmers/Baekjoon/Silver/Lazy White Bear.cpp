#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(1000001, 0);
    for (int i = 0; i < n; i++)
    {
        int g, x;
        cin >> g >> x;
        v[x] = g;
    }

    k = 2 * k + 1;
    int sum = 0, ans = 0;
    for (int i = 0; i <= 1000001; i++)
    {
        if (i >= k)
            sum -= v[i - k];

        sum += v[i];
        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}