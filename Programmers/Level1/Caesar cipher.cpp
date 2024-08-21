#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    string answer = "";

    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            if (c + n > 'Z')
                c = c - 26 + n;
            else
                c += n;
        }
        else if (c >= 'a' && c <= 'z')
        {
            if (c + n > 'z')
                c = c - 26 + n;
            else
                c += n;
        }
        answer += c;
    }

    return answer;
}