#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size(), 0);

    stack<int> s;
    for (int i = 0; i < prices.size(); i++)
    {
        // 주식이 떨어질 때
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        answer[s.top()] = prices.size() - 1 - s.top();
        s.pop();
    }

    return answer;
}