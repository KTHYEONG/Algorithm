#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b > 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int solution(vector<int> arr)
{
    int answer = 0;

    int num = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        num = num * arr[i] / gcd(num, arr[i]);
    }
    answer = num;

    return answer;
}