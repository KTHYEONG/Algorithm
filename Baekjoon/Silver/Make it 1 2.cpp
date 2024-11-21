#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x;
    cin >> x;

    vector<int> minCnt(x + 1, 0);
    for (int i = 1; i <= x; i++)
        minCnt[i] = i;

    for (int i = 2; i <= x; i++)
    {
        if (i % 3 == 0)
            minCnt[i] = min(minCnt[i], minCnt[i / 3]);
        if (i % 2 == 0)
            minCnt[i] = min(minCnt[i], minCnt[i / 2]);

        minCnt[i] = min(minCnt[i], minCnt[i - 1]) + 1;
    }

    cout << minCnt[x] - 1 << endl;

    while (x != 0)
    {
        cout << x << " ";
        if (minCnt[x] == minCnt[x - 1] + 1)
            x -= 1;
        else if (x % 3 == 0 && minCnt[x] == minCnt[x / 3] + 1)
            x /= 3;
        else if (x % 2 == 0 && minCnt[x] == minCnt[x / 2] + 1)
            x /= 2;
    }

    return 0;
}