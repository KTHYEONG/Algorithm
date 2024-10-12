#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    int idx = 0;
    for (int i = 0; i < number.length() - k; i++)
    {
        char maxNum = number[idx];
        int maxIdx = idx;
        for (int j = idx + 1; j <= k + i; j++)
        {
            if (maxNum < number[j])
            {
                maxNum = number[j];
                maxIdx = j;
            }
        }

        answer += maxNum;
        idx = maxIdx + 1;
    }

    return answer;
}