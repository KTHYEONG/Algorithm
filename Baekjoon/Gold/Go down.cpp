#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> maxV(3, 0);
    vector<int> minV(3, 0);
    cin >> maxV[0] >> maxV[1] >> maxV[2];
    minV[0] = maxV[0];
    minV[1] = maxV[1];
    minV[2] = maxV[2];

    vector<int> num(3, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> num[0] >> num[1] >> num[2];

        int prev0 = maxV[0];
        int prev1 = maxV[1];
        int prev2 = maxV[2];

        maxV[0] = max(prev0, prev1) + num[0];
        maxV[1] = max(prev0, max(prev1, prev2)) + num[1];
        maxV[2] = max(prev1, prev2) + num[2];

        prev0 = minV[0];
        prev1 = minV[1];
        prev2 = minV[2];

        minV[0] = min(prev0, prev1) + num[0];
        minV[1] = min(prev0, min(prev1, prev2)) + num[1];
        minV[2] = min(prev1, prev2) + num[2];
    }

    int maxNum = max(maxV[0], max(maxV[1], maxV[2]));
    int minNum = min(minV[0], min(minV[1], minV[2]));

    cout << maxNum << " " << minNum;

    return 0;
}