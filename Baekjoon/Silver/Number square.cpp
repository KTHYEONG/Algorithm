#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            v[i][j] = temp[j] - '0';
        }
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < min(n, m); k++)
            {
                if (i + k < n && j + k < m)
                {
                    if (v[i][j + k] == v[i][j] && v[i + k][j] == v[i][j] && v[i + k][j + k] == v[i][j])
                    {
                        ans = max(ans, (k + 1) * (k + 1));
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}