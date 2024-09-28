#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order)
{
    int answer = 0;

    stack<int> s;
    int num = 1;
    for (int item : order)
    {
        while (num <= item)
            s.push(num++);

        if (!s.empty() && s.top() == item)
        {
            s.pop();
            answer++;
        }
        else
            break;
    }

    return answer;
}