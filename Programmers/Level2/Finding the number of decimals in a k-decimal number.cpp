#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(long num)
{
    if (num <= 1)
        return false;

    for (long i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    vector<long> v;

    while (n > 0)
    {
        long num = n % k;
        v.push_back(num);
        n /= k;
    }
    reverse(v.begin(), v.end());

    long sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        long num = v[i];
        if (num != 0)
        {
            sum *= 10;
            sum += num;
        }
        else
        {
            if (is_prime(sum) == true)
                answer++;
            sum = 0;
        }
    }

    if (sum != 0)
    {
        if (is_prime(sum) == true)
            answer++;
    }

    return answer;
}