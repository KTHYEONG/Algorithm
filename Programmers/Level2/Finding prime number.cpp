#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

bool is_prime_func(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(string numbers)
{
    int answer = 0;
    set<int> s;

    sort(numbers.begin(), numbers.end());

    do
    {
        string str;
        for (int i = 0; i < numbers.size(); i++)
        {
            str += numbers[i];
            if (is_prime_func(stoi(str)))
                s.insert(stoi(str));
        }

    } while (next_permutation(numbers.begin(), numbers.end()));

    answer = s.size();

    return answer;
}