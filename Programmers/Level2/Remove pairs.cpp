#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> stk;

    for (char c : s)
    {
        // Remove pairs, else push
        if (!stk.empty() && stk.top() == c)
        {
            stk.pop();
        }
        else
        {
            stk.push(c);
        }
    }

    // stk empty == 모든 짝 제거 완료
    answer = stk.empty() ? 1 : 0;

    return answer;
}