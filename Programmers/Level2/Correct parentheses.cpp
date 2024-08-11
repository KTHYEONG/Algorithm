#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for (char element : s)
    {
        if (element == '(')
            stk.push(element);
        else if (element == ')' && !stk.empty())
            stk.pop();
        else
            return false;
    }

    if (!stk.empty())
        answer = false;

    return answer;
}