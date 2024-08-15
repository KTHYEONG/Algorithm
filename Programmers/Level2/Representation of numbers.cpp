#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int start = 1, num = 1;
    int sum = 0;
    while (start <= n)
    {
        sum += num++;
        if (sum == n)
        {
            answer++;
            start++;
            num = start;
            sum = 0;
        }
        else if (sum > n)
        {
            start++;
            num = start;
            sum = 0;
        }
    }

    return answer;
}