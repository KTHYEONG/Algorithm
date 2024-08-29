#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.length(); i++)
    {
        stack<char> stk;
        bool check = true;

        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else if (!stk.empty() && c == ')' && stk.top() == '(')
                stk.pop();
            else if (!stk.empty() && c == ']' && stk.top() == '[')
                stk.pop();
            else if (!stk.empty() && c == '}' && stk.top() == '{')
                stk.pop();
            else
            {
                check = false;
                break;
            }
        }

        if (check == true && stk.empty())
            answer++;

        s = s.substr(1) + s[0];
    }

    return answer;
}