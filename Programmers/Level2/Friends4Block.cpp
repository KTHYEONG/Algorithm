#include <string>
#include <vector>
#include <map>

using namespace std;

bool check(int i, int j, vector<string> &board)
{
    char c = board[i][j];
    // 2 x 2 체크
    if (c != '-' && c == board[i][j + 1] && c == board[i + 1][j] && c == board[i + 1][j + 1])
        return true;
    else
        return false;
}

int remove(int m, int n, vector<string> &board)
{
    map<pair<int, int>, bool> table;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < m && j + 1 < n && check(i, j, board) == true)
            {
                table.insert({make_pair(i, j), true});
                table.insert({make_pair(i, j + 1), true});
                table.insert({make_pair(i + 1, j), true});
                table.insert({make_pair(i + 1, j + 1), true});
            }
        }
    }

    // 삭제
    for (auto it = table.begin(); it != table.end(); it++)
        board[it->first.first][it->first.second] = '-';

    return table.size();
}

void move(int m, int n, vector<string> &board)
{
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (board[i][j] == '-')
            {
                int y = i;
                while (y >= 0)
                {
                    if (board[y][j] != '-')
                    {
                        board[i][j] = board[y][j];
                        board[y][j] = '-';
                        break;
                    }
                    else
                        y--;
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    int eraseNum;
    while (1)
    {
        eraseNum = remove(m, n, board);
        if (eraseNum != 0)
        {
            answer += eraseNum;
            move(m, n, board);
        }
        else
            break;
    }

    return answer;
}