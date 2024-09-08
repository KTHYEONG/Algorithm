#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;

    vector<pair<int, double>> failure;
    for (int stage = 1; stage <= N; stage++)
    {
        int reach = 0;
        int reachNoClear = 0;
        for (int i = 0; i < stages.size(); i++)
        {
            if (stages[i] >= stage)
            {
                reach++;
                if (stages[i] == stage)
                    reachNoClear++;
            }
        }

        if (reach == 0)
            failure.push_back({stage, 0});
        else
            failure.push_back({stage, (double)reachNoClear / reach});
    }

    sort(failure.begin(), failure.end(), [](const pair<int, double> &a, const pair<int, double> &b)
         { if (a.second == b.second)
            return a.first < b.first;
       return a.second > b.second; });

    for (auto temp : failure)
        answer.push_back(temp.first);

    return answer;
}