#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    int size = numbers.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int num = numbers[i] + numbers[j];
            // 중복이 없는 수만 추가
            if (find(answer.begin(), answer.end(), num) == answer.end())
                answer.push_back(num);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}