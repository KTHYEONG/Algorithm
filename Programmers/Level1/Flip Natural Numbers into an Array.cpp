#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(long long n)
{
    vector<int> answer;
    string str = to_string(n);
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char element = str[i] - '0';
        answer.push_back(element);
    }

    return answer;
}

int main()
{
    long long n;
    cin >> n;
    vector<int> ans = solution(n);
    for (int temp : ans)
    {
        cout << temp << endl;
    }
    return 0;
}