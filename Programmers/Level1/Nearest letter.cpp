#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;

    for (int i = 0; i < s.length(); i++)
    {
        int idx = -1;
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j])
                idx = i - j;
        }
        answer.push_back(idx);
    }

    return answer;
}