#include <string>
#include <vector>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;

    int p_len = p.length();
    for (int i = 0; i <= t.length() - p_len; i++)
    {
        long long num = stoll(p);
        long long goal = stoll(t.substr(i, p_len));
        if (goal <= num)
            answer++;
    }

    return answer;
}