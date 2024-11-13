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

    int x;
    cin >> x;

    int startIdx = 0, endIdx = n - 1;
    int cnt = 0;
    while (startIdx < endIdx)
    {
        int sum = v[startIdx] + v[endIdx];
        if (sum == x)
        {
            cnt++;
            startIdx++;
            endIdx--;
        }
        else if (sum < x)
        {
            startIdx++;
        }
        else
        {
            endIdx--;
        }
    }

    cout << cnt;

    return 0;
}