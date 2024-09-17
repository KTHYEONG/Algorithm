#include <string>
#include <vector>

using namespace std;

int answer = 0;
int cnt = -1;
string vowel = "AEIOU";

void dfs(string s, string word)
{
    cnt++;

    if (s == word)
    {
        answer = cnt;
        return;
    }

    if (s.length() >= 5)
        return;

    for (int i = 0; i < 5; i++)
        dfs(s + vowel[i], word);
}

int solution(string word)
{
    dfs("", word);

    return answer;
}