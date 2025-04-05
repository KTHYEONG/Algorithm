#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Warehouse Polygon
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> pillars(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> pillars[i].first >> pillars[i].second;
    }

    sort(pillars.begin(), pillars.end());

    int area = 0;
    int leftHeight = pillars[0].second;
    int leftPos = pillars[0].first;
    for (int i = 0; i < pillars.size(); i++)
    {
        if (pillars[i].second >= leftHeight)
        {
            area += (pillars[i].first - leftPos) * leftHeight;
            leftHeight = pillars[i].second;
            leftPos = pillars[i].first;
        }
    }

    int rightHeight = pillars[n - 1].second;
    int rightPos = pillars[n - 1].first;
    for (int i = n - 1; i >= 0; i--)
    {
        if (pillars[i].second > rightHeight)
        {
            area += (rightPos - pillars[i].first) * rightHeight;
            rightHeight = pillars[i].second;
            rightPos = pillars[i].first;
        }
    }

    cout << area + leftHeight;

    return 0;
}