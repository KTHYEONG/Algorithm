#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;

    unordered_map<char, int> minKey;
    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].length(); j++)
        {
            char c = keymap[i][j];
            if (minKey.find(c) == minKey.end())
                minKey[c] = j + 1;
            else
                minKey[c] = min(minKey[c], j + 1);
        }
    }

    for (string &s : targets)
    {
        int sum = 0;
        for (char c : s)
        {
            if (minKey.find(c) != minKey.end())
                sum += minKey[c];
            else
            {
                sum = -1;
                break;
            }
        }
        answer.push_back(sum);
    }

    return answer;
}