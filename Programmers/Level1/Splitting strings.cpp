#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 0;

    int prev = 0, cur = 0;
    string check = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (check == "")
        {
            check = to_string(s[i]);
            prev++;
            continue;
        }

        if (check == to_string(s[i]))
            prev++;
        else
            cur++;

        if (prev == cur)
        {
            answer++;
            prev = 0;
            cur = 0;
            check = "";
        }
    }

    // 마지막 1개가 남은 경우
    if (prev != 0)
        answer++;

    return answer;
}