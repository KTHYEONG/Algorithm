#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;

    queue<int> q;

    int sum = 0;
    int idx = 0;
    while (true)
    {
        // 마지막 트럭
        if (idx == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }

        answer++;
        int curWeight = truck_weights[idx];

        // 다리를 건너는 경우
        if (q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
        }

        if (sum + curWeight <= weight)
        {
            sum += curWeight;
            q.push(curWeight);
            idx++;
        }
        else
        {
            q.push(0);
        }
    }

    return answer;
}