#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v1(n);
    vector<int> v2(m);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    vector<int> ans;
    int v1Idx = 0, v2Idx = 0;
    while (v1Idx < n && v2Idx < m)
    {
        if (v1[v1Idx] <= v2[v2Idx])
            ans.push_back(v1[v1Idx++]);
        else
            ans.push_back(v2[v2Idx++]);
    }

    while (v1Idx < n)
        ans.push_back(v1[v1Idx++]);

    while (v2Idx < m)
        ans.push_back(v2[v2Idx++]);

    for (int item : ans)
        cout << item << " ";

    return 0;
}