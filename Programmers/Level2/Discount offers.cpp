#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    unordered_map<string, int> table;
    for (int i = 0; i < want.size(); i++)
        table.insert({want[i], number[i]});

    unordered_map<string, int> temp = table;
    for (int i = 0; i <= discount.size() - 10; i++)
    {
        bool flag = true;
        for (int j = i; j < i + 10; j++)
        {
            if (table.find(discount[j]) != table.end())
                table[discount[j]]--;
        }

        // 원하는 품목을 모두 살 수 있는지 체크
        for (int j = 0; j < want.size(); j++)
        {
            if (table[want[j]] != 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            answer++;

        // table 복구
        table = temp;
    }

    return answer;
}