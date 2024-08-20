#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    vector<pair<int, int>> v;
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] > sizes[i][1])
            v.push_back({sizes[i][0], sizes[i][1]});
        else
            v.push_back({sizes[i][1], sizes[i][0]});
    }

    // 큰 수들 중에서 max값, 작은 수들 중에서 max값 찾기
    int max0 = 0, max1 = 0;
    for (auto num : v)
    {
        if (num.first > max0)
            max0 = num.first;

        if (num.second > max1)
            max1 = num.second;
    }
    answer = max0 * max1;

    return answer;
}