#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    vector<int> HallOfTheFame;
    for (auto num : score)
    {
        HallOfTheFame.push_back(num);
        sort(HallOfTheFame.begin(), HallOfTheFame.end());
        if (HallOfTheFame.size() > k)
        {
            HallOfTheFame.erase(HallOfTheFame.begin());
        }
        answer.push_back(HallOfTheFame[0]);
    }

    return answer;
}