#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s)
{
    string answer = "";
    stringstream ss(s);
    vector<int> numbers;
    int num;
    while (ss >> num)
        numbers.push_back(num);

    answer += to_string(*min_element(numbers.begin(), numbers.end()));
    answer += " ";
    answer += to_string(*max_element(numbers.begin(), numbers.end()));
    return answer;
}

int main()
{
    solution("-1 2 3 4");
    return 0;
}