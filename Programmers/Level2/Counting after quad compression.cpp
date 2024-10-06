#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

void search(int x, int y, int n, vector<int> &answer)
{
    bool zero = true, one = true;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (v[i][j] == 0)
                one = false;
            if (v[i][j] == 1)
                zero = false;

            if (!zero && !one)
                break;
        }
    }

    if (zero == true)
    {
        answer[0]++;
        return;
    }
    if (one == true)
    {
        answer[1]++;
        return;
    }

    // 사분면으로 나눠서 탐색
    search(x, y, n / 2, answer);
    search(x, y + n / 2, n / 2, answer);
    search(x + n / 2, y, n / 2, answer);
    search(x + n / 2, y + n / 2, n / 2, answer);
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer(2);

    v = arr;
    search(0, 0, arr.size(), answer);

    return answer;
}