#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

string IntToBinaryString(int num)
{
    string temp = "";
    while (num > 0)
    {
        temp = (num % 2 == 0 ? "0" : "1") + temp;
        num /= 2;
    }

    return temp;
}

vector<int> solution(string s)
{
    vector<int> answer;
    int change = 0;
    int count = 0;
    while (s != "1")
    {
        // 문자열에서 0제거 및 카운트
        int OriginalLen = s.length();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        int ErasedLen = s.length();
        count += OriginalLen - ErasedLen;

        // 정수 -> 2진수 형태의 문자열 변환
        s = IntToBinaryString(ErasedLen);
        change++;
    }
    answer.push_back(change);
    answer.push_back(count);

    return answer;
}