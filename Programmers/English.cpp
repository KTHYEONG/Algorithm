#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, string> vocabulary;

    vocabulary["statement"] = "진술 / 서술 / 성명";
    vocabulary["motivate"] = "동기를 부여하다 / 이유(원인)가 되다";
    vocabulary["strengths and weaknesses / merits and demerits"] = "장단점";
    vocabulary["embarrassed"] = "당황하다";
    vocabulary["maintain"] = "유지하다 / 주장하다";
    vocabulary["achieve"] = "달성하다 / 잘 해내다";
    vocabulary["turn into"] = "~으로 변하다";
    vocabulary["familiar"] = "익숙한 / 스스럼없는";

    for (const auto &entry : vocabulary)
    {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
