#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    while (!progresses.empty())
    {
        for (int i = 0; i < progresses.size(); i++)
            progresses[i] += speeds[i];

        int cnt = 0;
        for (int i = 0; i < progresses.size(); i++)
        {
            if (progresses[i] >= 100)
                cnt++;
            else
                break;
        }

        for (int i = 0; i < cnt; i++)
        {
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
        }

        if (cnt != 0)
            answer.push_back(cnt);
    }

    return answer;
}

int main()
{

    solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1});

    return 0;
}