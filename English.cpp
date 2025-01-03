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
    vocabulary["aim"] = "조준 / ~을 목표로 하다";
    vocabulary["immersion"] = "몰입";
    vocabulary["Even if"] = "~일지라도";
    vocabulary["Depend on"] = "~에 의존하다 / 확신하다";
    vocabulary["As well"] = "또한 / 역시";
    vocabulary["Versatile"] = "다재다능한 / 다목적의";
    vocabulary["Effortless"] = "자연스러운 / 수월해 보이는";
    vocabulary["Stand out"] = "눈에 띄다 / 튀어나오다 / 견디다";
    vocabulary["Outweigh"] = "~보다 더 크다 / 대단하다";
    vocabulary["Lopsided"] = "한쪽으로 치우친";
    vocabulary["Undesirable"] = "원하지 않는 / 바람직하지 않은";
    vocabulary["Pale"] = "창백한 / 연한";
    vocabulary["Curious"] = "궁금한 / 특이한";

    for (const auto &entry : vocabulary)
    {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
