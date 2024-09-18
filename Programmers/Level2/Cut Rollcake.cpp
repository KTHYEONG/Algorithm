#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;

    unordered_map<int, int> first;
    unordered_map<int, int> second;

    for (int i = 0; i < topping.size(); i++)
        second[topping[i]]++;

    for (int i = 0; i < topping.size(); i++)
    {
        first[topping[i]]++;
        second[topping[i]]--;
        if (second[topping[i]] == 0)
            second.erase(topping[i]);

        if (first.size() == second.size())
            answer++;
    }

    return answer;
}