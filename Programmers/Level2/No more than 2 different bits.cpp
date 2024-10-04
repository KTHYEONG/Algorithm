#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long number = numbers[i];

        // 짝수인 경우 다음 수가 비트 차이 1이면서 제일 작은 수
        if (number % 2 == 0)
            answer.push_back(number + 1);
        else
        {
            // 최하위 비트 0을 1로 변환, 그 다음 비트를 0으로 변환
            long long smallestBit = (number + 1) & (-number);
            long long result = (number | smallestBit) & (~(smallestBit >> 1));

            answer.push_back(result);
        }
    }

    return answer;
}