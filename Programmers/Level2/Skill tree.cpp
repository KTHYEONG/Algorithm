#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for (string curSkill : skill_trees)
    {
        string temp = skill;

        bool flag = true;
        for (char c : curSkill)
        {
            auto it = find(temp.begin(), temp.end(), c);

            if (it != temp.end())
            {
                // 첫 번째 스킬이 아닌 경우 순서가 잘못됨
                if (c != temp.front())
                {
                    flag = false;
                    break;
                }
                // 순서가 맞으면 첫 번째 스킬을 제거
                else
                    temp.erase(temp.begin());
            }
        }

        if (flag)
            answer++;
    }

    return answer;
}
