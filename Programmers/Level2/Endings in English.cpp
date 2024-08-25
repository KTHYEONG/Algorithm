#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;

    int cnt1 = 1;
    int cnt2 = 1;
    set<string> table;
    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        // table에 이미 존재한 단어인 경우 -> 탈락
        if (table.find(word) != table.end())
        {
            answer = {cnt1, cnt2};
            return answer;
        }

        table.insert(word);

        // 이전 word의 마지막과 현재 word의 처음 비교
        if (i > 0 && words[i - 1].back() != word.front())
        {
            answer = {cnt1, cnt2};
            return answer;
        }

        cnt1++;
        if (cnt1 > n)
        {
            cnt1 = 1;
            cnt2++;
        }
    }

    return {0, 0};
}