#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string w;
        cin >> w;

        int k;
        cin >> k;

        vector<vector<int>> v(26);
        for (int j = 0; j < w.length(); j++)
            v[w[j] - 'a'].push_back(j);

        int minW = INT_MAX;
        int maxW = -1;
        for (char c = 'a'; c <= 'z'; c++)
        {
            int idx = c - 'a';
            for (int start = 0, end = k - 1; end < v[idx].size(); start++, end++)
            {
                int len = v[idx][end] - v[idx][start] + 1;
                minW = min(minW, len);
                maxW = max(maxW, len);
            }
        }

        if (minW == INT_MAX)
            cout << -1 << endl;
        else
            cout << minW << ' ' << maxW << endl;
    }

    return 0;
}