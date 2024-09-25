#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;

    int n = land.size();
    // DP, 이전 행의 열들중 자신의 열에 해당하지 않는 값들 중 최대값을 선택하여 더함.
    for (int i = 1; i < n; i++)
    {
        land[i][0] += max({land[i - 1][1], land[i - 1][2], land[i - 1][3]});
        land[i][1] += max({land[i - 1][0], land[i - 1][2], land[i - 1][3]});
        land[i][2] += max({land[i - 1][0], land[i - 1][1], land[i - 1][3]});
        land[i][3] += max({land[i - 1][0], land[i - 1][1], land[i - 1][2]});
    }

    answer = *max_element(land[n - 1].begin(), land[n - 1].end());

    return answer;
}