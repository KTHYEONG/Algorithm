#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<char>> v(n, vector<char>(m, '-'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
            {
                continue;
            }

            // 오른쪽으로 탐색
            if (v[i][j] == '-')
            {
                for (int k = j; k < m; k++)
                {
                    if (v[i][k] != '-')
                    {
                        break;
                    }
                    else
                    {
                        visited[i][k] = true;
                    }
                }
            } // 아래쪽으로 탐색
            else if (v[i][j] == '|')
            {
                for (int k = i; k < n; k++)
                {
                    if (v[k][j] != '|')
                    {
                        break;
                    }
                    else
                    {
                        visited[k][j] = true;
                    }
                }
            }
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}