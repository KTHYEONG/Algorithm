#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int startIdx = 0, endIdx = n - 1;
    int gap = INT_MAX;
    vector<int> ans(2);
    while (startIdx < endIdx)
    {
        int sum = v[startIdx] + v[endIdx];
        if (sum == 0)
        {
            ans[0] = v[startIdx];
            ans[1] = v[endIdx];
            break;
        }
        else
        {
            if (abs(sum) < gap)
            {
                gap = abs(sum);
                ans[0] = v[startIdx];
                ans[1] = v[endIdx];
            }
        }

        if (sum >= 0)
        {
            endIdx--;
        }
        else
        {
            startIdx++;
        }
    }

    cout << ans[0] << " " << ans[1];

    return 0;
}