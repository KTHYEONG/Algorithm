#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food)
{
    string answer = "";

    for (int i = 1; i < food.size(); i++)
    {
        int item = food[i];
        if (item % 2 != 0)
            item--;
        item /= 2;

        for (int j = 0; j < item; j++)
            answer += to_string(i);
    }

    string temp = answer;
    reverse(temp.begin(), temp.end());
    answer += "0";
    answer += temp;

    return answer;
}