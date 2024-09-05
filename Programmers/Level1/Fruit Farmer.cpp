#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score)
{
    int answer = 0;

    sort(score.begin(), score.end(), greater<>());
    for (int i = 0; i < score.size(); i += m)
    {
        int num = score[i];
        for (int j = i + 1; j < i + m; j++)
        {
            if (score[j] < num)
                num = score[j];
        }
        answer += num * m;
    }

    return answer;
}