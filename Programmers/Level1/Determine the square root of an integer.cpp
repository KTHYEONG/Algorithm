#include <iostream>
#include <cmath>

using namespace std;

long long solution(long long n)
{
    long long answer = 1;
    while (pow(answer, 2) <= n)
    {
        if (pow(answer, 2) == n)
        {
            return (long long)pow(answer + 1, 2);
        }
        answer++;
    }

    return -1;
}

int main()
{
    long long n;
    cin >> n;
    long long ans = solution(n);
    cout << ans;
    return 0;
}