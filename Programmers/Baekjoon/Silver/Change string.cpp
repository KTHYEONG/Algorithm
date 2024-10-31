#include <iostream>
#include <limits.h>

using namespace std;

int solution(string &s, int start, int len)
{
    int result = 0;
    for (int i = start; i < start + len; i++)
    {
        if (s[(i + 1) % s.length()] == 'a')
            result++;
    }

    return result;
}

int main()
{
    string str;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'b')
            cnt++;
    }

    int ans = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        ans = min(ans, solution(str, i, cnt));
    }

    cout << ans;

    return 0;
}