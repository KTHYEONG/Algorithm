#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;

    unordered_map<string, int> table;
    for (int i = 0; i < 26; i++)
    {
        string key(1, 'A' + i);
        table[key] = i + 1;
    }

    int idx = 27;
    for (int i = 0; i < msg.length();)
    {
        string checkString(1, msg[i]);
        int j = i + 1;
        // table에서 string을 찾은 경우 --> 더 긴 문자열 탐색
        while (j < msg.length() && table.find(checkString + msg[j]) != table.end())
        {
            checkString += msg[j];
            j++;
        }

        answer.push_back(table[checkString]);

        if (j <= msg.length())
            table[checkString + msg[j]] = idx++;

        i += checkString.length();
    }

    return answer;
}