#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c, r;
    cin >> c >> r;

    int k;
    cin >> k;

    if (k > c * r)
    {
        cout << 0;
        return 0;
    }
    else if (k == 1)
    {
        cout << 1 << ' ' << 1;
        return 0;
    }

    // 방향 배열 --> 편의상 시계방향으로 90도 회전시킨 상태로 생각
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool visit[1001][1001] = {false};

    int x = 1, y = 1;
    visit[x][y] = true;
    int idx = 0, num = 1;
    while (true)
    {
        int nx = x + dx[idx];
        int ny = y + dy[idx];
        if (nx > c || nx <= 0 || ny > r || ny <= 0 || visit[nx][ny])
        {
            idx = (idx + 1) % 4;
        }

        x += dx[idx];
        y += dy[idx];
        visit[x][y] = true;
        num++;

        if (num == k)
            break;
    }

    cout << x << ' ' << y;

    return 0;
}