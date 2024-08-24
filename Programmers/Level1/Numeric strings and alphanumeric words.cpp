#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<string> numbers{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

    string temp;
    for (auto c : s)
    {
        if (isdigit(c))
            answer = answer * 10 + c - '0';
        else
            temp += c;
        for (int i = 0; i <= 9; i++)
        {
            if (numbers[i] == temp)
            {
                answer = answer * 10 + i;
                temp = "";
                break;
            }
        }
    }

    return answer;
}