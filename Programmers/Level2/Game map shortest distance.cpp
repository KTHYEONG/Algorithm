#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    int n = maps.size();
    int m = maps[0].size();
    bool visit[101][101] = {};
    int distance[101][101];
    for (int i = 0; i < 101; i++)
        fill(distance[i], distance[i] + 101, -1);

    int limitX[4] = {0, 1, -1, 0};
    int limitY[4] = {1, 0, 0, -1};

    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = true;
    distance[0][0] = 1;

    int x, y;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1)
            return distance[n - 1][m - 1];

        for (int i = 0; i < 4; i++)
        {
            int move_x = x + limitX[i];
            int move_y = y + limitY[i];
            if (move_x >= 0 && move_y >= 0 && move_x < n && move_y < m)
            {
                if (maps[move_x][move_y] == 1 && visit[move_x][move_y] == false)
                {
                    q.push({move_x, move_y});
                    visit[move_x][move_y] = true;
                    distance[move_x][move_y] = distance[x][y] + 1;
                }
            }
        }
    }

    if (distance[n - 1][m - 1] == -1)
        answer = -1;
    else
        answer = distance[n - 1][m - 1];

    return answer;
}