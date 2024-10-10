#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> table(n, vector<int>(n));

    int x = 0, y = 0;
    int value = 1;
    int dir = 0;
    for (int i = 0; i < n; i++)
    {
        switch (dir)
        {
        // 아래
        case 0:
            for (int j = i; j < n; j++)
            {
                table[x++][y] = value++;
            }

            // 다음 인덱스로 스타트 지점 설정
            x--;
            y++;

            dir = 1;
            break;
        // 오른쪽
        case 1:
            for (int j = i; j < n; j++)
            {
                table[x][y++] = value++;
            }

            x--;
            y -= 2;

            dir = 2;
            break;
        // 대각선
        case 2:
            for (int j = i; j < n; j++)
            {
                table[x--][y--] = value++;
            }

            x += 2;
            y++;

            dir = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            answer.push_back(table[i][j]);
        }
    }

    return answer;
}