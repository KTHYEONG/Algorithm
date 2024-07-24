#include <string>
#include <iostream>

using namespace std;

bool solution(string s);

int main()
{
    string s;
    cin >> s;
    bool ans = solution(s);
    cout << ans;
}

bool solution(string s)
{
    bool answer = true;

    int p_count = 0;
    int y_count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (tolower(s[i]) == 'p' || tolower(s[i] == 'P'))
        {
            p_count++;
        }
        else if (tolower(s[i]) == 'y' || tolower(s[i] == 'Y'))
        {
            y_count++;
        }
    }

    if (p_count != y_count)
    {
        answer = false;
    }

    return answer;
}