#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    while (true)
    {
        auto highestPriority = max_element(priorities.begin(), priorities.end());
        int topNum = priorities.front();

        if (topNum == *highestPriority)
        {
            priorities.erase(priorities.begin());
            answer++;
            if (location == 0)
                break;
            else
                location--;
        }
        else
        {
            priorities.push_back(topNum);
            priorities.erase(priorities.begin());

            if (location == 0)
                location = priorities.size() - 1;
            else
                location--;
        }
    }

    return answer;
}