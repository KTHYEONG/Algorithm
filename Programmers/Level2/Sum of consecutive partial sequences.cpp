#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
    int sequenceSize = sequence.size();
    vector<int> answer = {0, sequenceSize};

    int sum = 0;
    int leftIdx = 0, rightIdx = -1;
    while (rightIdx < sequenceSize)
    {
        if (sum == k)
        {
            if (rightIdx - leftIdx < answer[1] - answer[0])
            {
                answer[0] = leftIdx;
                answer[1] = rightIdx;
            }

            sum -= sequence[leftIdx++];
        }
        else if (sum < k)
            sum += sequence[++rightIdx];
        else
            sum -= sequence[leftIdx++];
    }

    return answer;
}