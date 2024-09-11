#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;

    int hit = 0;
    int zero = 0;
    for (int num : lottos)
    {
        if (find(win_nums.begin(), win_nums.end(), num) != win_nums.end())
            hit++;

        if (num == 0)
            zero++;
    }

    int highest = hit + zero;
    int lowest = hit;
    if (hit < 2)
        lowest = 1;
    if (highest == 0)
        highest = 1;

    answer.push_back(7 - highest);
    answer.push_back(7 - lowest);

    return answer;
}