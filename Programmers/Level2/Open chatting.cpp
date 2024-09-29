#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    vector<pair<string, string>> action;
    map<string, string> userName;
    // 최종 닉네임을 userName에 저장, 어떤 행동을 했었는지 action에 저장
    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string inOrOut, id, name;
        ss >> inOrOut >> id;
        if (inOrOut != "Leave")
        {
            ss >> name;
            userName[id] = name;
        }
        action.push_back({inOrOut, id});
    }

    for (int i = 0; i < record.size(); i++)
    {
        string result = "";
        // 최종 닉네임 추가
        result += userName[action[i].second];
        if (action[i].first == "Enter")
            result += "님이 들어왔습니다.";
        else if (action[i].first == "Leave")
            result += "님이 나갔습니다.";
        else if (action[i].first == "Change")
            continue;
        answer.push_back(result);
    }

    return answer;
}