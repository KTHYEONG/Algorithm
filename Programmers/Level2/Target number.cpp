#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    queue<pair<int, int>> q;
    q.push({numbers[0], 0});
    q.push({-numbers[0], 0});

    int idx = 1;
    while (!q.empty())
    {
        int sum = q.front().first;
        int idx = q.front().second;
        q.pop();

        if (idx == numbers.size() - 1)
        {
            if (sum == target)
                answer++;
        }
        else
        {
            q.push({sum + numbers[idx + 1], idx + 1});
            q.push({sum - numbers[idx + 1], idx + 1});
        }
    }

    return answer;
}