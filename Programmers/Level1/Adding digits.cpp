#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    int i = 10;
    while (n > 0)
    {
        answer += n % i;
        n /= i;
    }

    return answer;
}

int main()
{
    int input;
    cin >> input;
    cout << solution(input);
    return 0;
}