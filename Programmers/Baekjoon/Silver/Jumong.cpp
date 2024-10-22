#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int startIdx = 0, endIdx = n - 1;
    int cnt = 0;
    while (startIdx < endIdx)
    {
        int sum = v[startIdx] + v[endIdx];
        if (sum == m)
        {
            cnt++;
            startIdx++;
            endIdx--;
        }
        else if (sum >= m)
            endIdx--;
        else
            startIdx++;
    }

    cout << cnt;

    return 0;
}