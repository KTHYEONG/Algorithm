#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 0;

    for (int i = 1; i <= number; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                cnt++;
                if (j != i / j)
                    cnt++;
            }
        }

        if (cnt > limit)
            answer += power;
        else
            answer += cnt;
    }

    return answer;
}