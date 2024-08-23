#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = -1;

    int idx = 0;
    while (true)
    {
        if (idx == s.length())
        {
            answer = 0;
            break;
        }

        string SubStr = s.substr(idx++, 2);
        if (SubStr[0] == SubStr[1])
        {
            s.replace(s.find(SubStr), 2, "");
            idx = 0;
        }

        if (s.length() == 0)
        {
            answer = 1;
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> a{1, 2, 3};
    cout << *a.begin();

    return 0;
}