#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    vector<int> ans(2);
    int leftIdx = 0, rightIdx = N - 1;
    int sum = 0, minNum = INT_MAX;
    while (leftIdx < rightIdx)
    {
        sum = v[leftIdx] + v[rightIdx];
        if (minNum > abs(sum))
        {
            minNum = abs(sum);
            ans[0] = v[leftIdx];
            ans[1] = v[rightIdx];
        }

        if (sum == 0)
            break;
        else if (sum < 0)
            leftIdx++;
        else
            rightIdx--;
    }

    cout << ans[0] << " " << ans[1];

    return 0;
}