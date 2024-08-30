#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer;

    map<string, int> table;
    for (int i = 0; i < name.size(); i++)
        table.insert({name[i], yearning[i]});

    for (auto v : photo)
    {
        int sum = 0;
        for (auto element : v)
            sum += table[element];

        answer.push_back(sum);
    }

    return answer;
}