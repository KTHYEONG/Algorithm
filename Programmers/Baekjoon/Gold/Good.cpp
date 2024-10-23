#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int GOOD = 0;
    for (int i = 0; i < n; i++)
    {
        int num = v[i];
        int leftIdx = 0, rightIdx = n - 1;
        while (leftIdx < rightIdx)
        {
            if (leftIdx == i)
            {
                leftIdx++;
                continue;
            }
            else if (rightIdx == i)
            {
                rightIdx--;
                continue;
            }

            int sum = v[leftIdx] + v[rightIdx];
            if (sum == num)
            {
                GOOD++;
                break;
            }

            if (sum < num)
                leftIdx++;
            else
                rightIdx--;
        }
    }

    cout << GOOD;

    return 0;
}