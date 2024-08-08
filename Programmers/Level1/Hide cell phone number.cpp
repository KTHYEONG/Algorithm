#include <string>
#include <vector>

using namespace std;

string solution(string phone_number)
{
    string answer = "";

    int length = phone_number.length() - 4;
    for (int i = 0; i < length; i++)
    {
        phone_number[i] = '*';
    }
    answer = phone_number;

    return answer;
}