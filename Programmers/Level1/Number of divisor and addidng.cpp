#include <string>
#include <vector>

using namespace std;

int solution(int left, int right)
{
    int answer = 0;
    for (; left <= right; left++)
    {
        int cnt = 0;
        for (int j = 1; j <= left; j++)
        {
            if (left % j == 0)
            {
                cnt++;
            }
        }

        answer += (cnt % 2 == 0) ? left : left * -1;
    }

    return answer;
}