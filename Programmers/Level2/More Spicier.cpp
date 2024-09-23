#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int element : scoville)
        pq.push(element);

    while (pq.size() > 1)
    {
        int TopNum = pq.top();
        pq.pop();

        if (TopNum >= K)
            return answer;

        int SecondNum = pq.top();
        pq.pop();

        int NewScoville = TopNum + (SecondNum * 2);
        pq.push(NewScoville);

        answer++;
    }

    // 모두 k이상 만들 수 없는 경우
    if (pq.top() < K)
        answer = -1;

    return answer;
}