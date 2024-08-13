#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    bool first = true;
    for (char c : s)
    {
        if (c == ' ')
        {
            answer += ' ';
            first = true;
        }
        else if (first)
        {
            answer += toupper(c);
            first = false;
        }
        else
            answer += tolower(c);
    }
    return answer;
}