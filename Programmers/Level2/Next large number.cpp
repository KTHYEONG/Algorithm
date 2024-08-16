#include <string>
#include <vector>

using namespace std;

int calculate_count1(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += n & 1;
        n >>= 1;
    }

    return cnt;
}

int solution(int n)
{
    int answer = 0;

    int cnt = calculate_count1(n);

    answer = n + 1;
    while (true)
    {
        int ans = calculate_count1(answer);
        if (cnt == ans)
            break;
        answer++;
    }

    return answer;
}