#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, goalNum;
    cin >> n >> goalNum;

    vector<vector<int>> v(n, vector<int>(n, 0));

    int num = n * n;
    int x = 0, y = 0, ansX = 0, ansY = 0;
    for (int i = n - 1; i > 0; i -= 2)
    {
        int cnt = 0;
        for (int j = 0; j < i * 4; j++, num--)
        {
            v[x][y] = num;
            if (num == goalNum)
            {
                ansX = x;
                ansY = y;
            }

            if (cnt == 0)
                x++;
            else if (cnt == 1)
                y++;
            else if (cnt == 2)
                x--;
            else if (cnt == 3)
                y--;

            // 상, 하, 좌, 우 방향 전환
            if ((j + 1) % i == 0)
                cnt++;
        }

        // 다음 단계 초기 위치 설정
        x++;
        y++;
    }

    if (n % 2 == 1)
    {
        v[x][y] = 1;
        if (goalNum == 1)
        {
            ansX = x;
            ansY = y;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << ansX + 1 << " " << ansY + 1;

    return 0;
}