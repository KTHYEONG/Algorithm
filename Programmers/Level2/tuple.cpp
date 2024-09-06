#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first > b.first;

    return a.second > b.second;
}

vector<int> solution(string s)
{
    vector<int> answer;

    map<int, int> table;

    string temp;
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] != '{' && s[i] != '}' && s[i] != ',')
        {
            temp += s[i];
            if (s[i + 1] != ',' && s[i + 1] != '}')
                continue;

            table[stoi(temp)]++;
        }
        temp = "";
    }

    vector<pair<int, int>> v(table.begin(), table.end());
    sort(v.begin(), v.end(), compare);

    for (auto num : v)
        answer.emplace_back(num.first);

    return answer;
}