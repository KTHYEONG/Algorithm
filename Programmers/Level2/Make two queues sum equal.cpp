#include <string>
#include <vector>
#include <numeric>

using namespace std;

int idx_func(int idx, int size)
{
    return idx + 1 >= 2 * size ? 0 : idx + 1;
}

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;

    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);

    // queue1 뒤에 queue2 연결
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());

    int q1StartIdx = 0, q1EndIdx = queue1.size() - 1;
    int q2StartIdx = queue2.size(), q2EndIdx = queue2.size() * 2 - 1;
    while (answer <= queue1.size() * 4)
    {
        if (sum1 > sum2)
        {
            sum1 -= queue1[q1StartIdx];
            sum2 += queue1[q1StartIdx];
            // 인덱스 포인터로 배열 조정
            q1StartIdx = idx_func(q1StartIdx, queue2.size());
            q2EndIdx = idx_func(q2EndIdx, queue2.size());
        }
        else if (sum1 < sum2)
        {
            sum1 += queue1[q2StartIdx];
            sum2 -= queue1[q2StartIdx];

            q2StartIdx = idx_func(q2StartIdx, queue2.size());
            q1EndIdx = idx_func(q1EndIdx, queue2.size());
        }
        else
            return answer;

        answer++;
    }

    return -1;
}
