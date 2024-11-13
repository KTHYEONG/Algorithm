#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    vector<long long> ans(3);
    long long minSum = LONG_MAX;
    for (int i = 0; i < n - 2; i++)
    {
        int leftIdx = i + 1, rightIdx = n - 1;
        while (leftIdx < rightIdx)
        {
            long long sum = v[i] + v[leftIdx] + v[rightIdx];
            if (abs(sum) < minSum)
            {
                minSum = abs(sum);
                ans[0] = v[i];
                ans[1] = v[leftIdx];
                ans[2] = v[rightIdx];
            }

            if (sum < 0)
                leftIdx++;
            else
                rightIdx--;
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2];

    return 0;
}