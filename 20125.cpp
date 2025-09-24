#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>> v;

int countLine(int x, int y, int dx, int dy)
{
    int cnt = 0;
    while (1 <= x && x <= n && 1 <= y && y <= n && v[x][y] == '*')
    {
        ++cnt;
        x += dx; y += dy;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.assign(n + 1, vector<char>(n + 1, '.'));

    pair<int, int> head = { -1,-1 };
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> v[i][j];
            if (head.first == -1 && v[i][j] == '*') head = { i, j };
        }
    }

    // heart
    pair<int, int> heart = { head.first + 1, head.second };

    // 팔: 심장 기준 좌/우 한 칸 옆
    int leftArm = countLine(heart.first, heart.second - 1, 0, -1);
    int rightArm = countLine(heart.first, heart.second + 1, 0, 1);

    // 허리: 심장 바로 아래
    int waist = countLine(heart.first + 1, heart.second, 1, 0);

    // 다리 시작 행: 심장행 + 허리길이 + 1
    int legStartRow = heart.first + waist + 1;

    // 다리: 시작 행에서 좌/우 한 칸
    int leftLeg = countLine(legStartRow, heart.second - 1, 1, 0);
    int rightLeg = countLine(legStartRow, heart.second + 1, 1, 0);

    cout << heart.first << ' ' << heart.second << '\n';
    cout << leftArm << ' ' << rightArm << ' ' << waist << ' ' << leftLeg << ' ' << rightLeg << '\n';

    return 0;
}
