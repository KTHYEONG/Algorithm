#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul)
{
    string answer = "";

    auto temp = find(seoul.begin(), seoul.end(), "Kim");
    answer = "김서방은 " + to_string(temp - seoul.begin()) + "에 있다";
    return answer;
}

int main()
{
    vector<string> data{"jane", "Kim"};
    string ans = solution(data);
    cout << ans;
    return 0;
}