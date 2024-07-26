#include <iostream>
#include <string>

using namespace std;

int solution(string s);

int main()
{
    string str;
    cin >> str;
    int ans = solution(str);
    cout << ans;

    return 0;
}

int solution(string s)
{
    int answer = 0;
    answer = stoi(s);

    return answer;
}