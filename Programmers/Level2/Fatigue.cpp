#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visit[8] = {0};

void dfs(int cnt, int k, vector<vector<int>> &dungeons)
{
    if (cnt > answer)
        answer = cnt;

    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visit[i] && dungeons[i][0] <= k)
        {
            visit[i] = true;
            dfs(cnt + 1, k - dungeons[i][1], dungeons);
            visit[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    dfs(0, k, dungeons);

    return answer;
}