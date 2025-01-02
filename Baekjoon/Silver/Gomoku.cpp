#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, 0, 1, -1};
int dy[4] = {0, 1, 1, 1};

int main()
{
    vector<vector<int>> v(20, vector<int>(20, 0));
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            if (v[i][j] == 0)
            {
                continue;
            }

            for (int k = 0; k < 4; k++)
            {
                bool flag = true;
                for (int l = 1; l <= 4; l++)
                {
                    int nx = i + l * dx[k];
                    int ny = j + l * dy[k];
                    if (nx < 1 || ny < 1 || nx > 19 || ny > 19 || v[i][j] != v[nx][ny])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    int x = i - dx[k];
                    int y = j - dy[k];
                    if (x >= 1 && y >= 1 && x <= 19 && y <= 19 && v[i][j] == v[x][y])
                    {
                        continue;
                    }
                    x = i + 5 * dx[k];
                    y = j + 5 * dy[k];
                    if (x >= 1 && y >= 1 && x <= 19 && y <= 19 && v[i][j] == v[x][y])
                    {
                        continue;
                    }

                    cout << v[i][j] << '\n';
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
    }

    // 승자가 없는 경우
    cout << 0 << endl;

    return 0;
}
