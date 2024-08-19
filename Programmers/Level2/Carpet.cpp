#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int carpet = brown + yellow;
    for (int i = 3; i <= carpet; i++)
    {
        int col = i;
        int row = carpet / col;

        // 카펫이 성립 불가능한 경우
        if (row < 3)
            continue;

        if (row >= col)
        {
            if ((row - 2) * (col - 2) == yellow)
            {
                answer.push_back(row);
                answer.push_back(col);
                break;
            }
        }
    }

    return answer;
}