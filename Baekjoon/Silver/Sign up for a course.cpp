#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int k, l;
    cin >> k >> l;

    unordered_map<string, int> ids;
    for (int i = 0; i < l; i++)
    {
        string id;
        cin >> id;
        ids[id] = i;
    }

    vector<pair<string, int>> v;
    for (auto &i : ids)
    {
        v.push_back(i);
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < min(k, (int)v.size()); i++)
    {
        cout << v[i].first << '\n';
    }

    return 0;
}