#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < t; i++)
    {
        string moves = "";
        cin >> moves;

        int x = 0, y = 0, dir = 0;
        int maxX = 0, minX = 0, maxY = 0, minY = 0;
        for (char move : moves)
        {
            switch (move)
            {
            case 'F':
                x += dx[dir];
                y += dy[dir];
                break;
            case 'B':
                x -= dx[dir];
                y -= dy[dir];
                break;
            case 'L':
                dir = (dir + 3) % 4;
                break;
            case 'R':
                dir = (dir + 1) % 4;
                break;
            }

            maxX = max(x, maxX);
            minX = min(x, minX);
            maxY = max(y, maxY);
            minY = min(y, minY);
        }

        int ans = (maxX - minX) * (maxY - minY);
        cout << ans << endl;
    }

    return 0;
}