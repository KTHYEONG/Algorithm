#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int calculate_time_func(string in, string out)
{
    // ':' 를 기준으로 구분하여 시간 계산
    int hours = stoi(out.substr(0, 2)) - stoi(in.substr(0, 2));
    int minutes = stoi(out.substr(3, 2)) - stoi(in.substr(3, 2));

    return hours * 60 + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, vector<string>> table;

    for (int i = 0; i < records.size(); i++)
    {
        stringstream ss(records[i]);
        string time, carNum, status;
        ss >> time >> carNum >> status;

        table[carNum].push_back(time);
    }

    for (auto it : table)
    {
        // 주차 내역이 홀수인 경우 -> 23:59에 출차하는 경우 추가
        if (it.second.size() % 2 != 0)
            it.second.push_back("23:59");

        vector<string> data = it.second;
        int totalTime = 0;
        for (int i = 0; i < data.size() - 1; i += 2)
            totalTime += calculate_time_func(data[i], data[i + 1]);

        // 요금 계산
        int fee = fees[1];
        if (totalTime > fees[0])
            fee += ceil(((double)totalTime - fees[0]) / fees[2]) * fees[3];
        answer.push_back(fee);
    }

    return answer;
}