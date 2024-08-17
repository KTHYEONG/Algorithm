#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    vector<int> base3;
    int temp = n;
    while (temp)
    {
        base3.push_back(temp % 3);
        temp /= 3;
    }

    int exp = 1;
    for (int i = base3.size() - 1; i >= 0; i--)
    {
        answer += base3[i] * exp;
        exp *= 3;
    }

    return answer;
}