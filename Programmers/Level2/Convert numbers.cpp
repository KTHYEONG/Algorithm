#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int solution(int x, int y, int n)
{
    if (x == y)
        return 0;

    int answer = -1;

    queue<pair<int, int>> q;
    set<int> visited;

    q.push({x, 0});
    while (!q.empty())
    {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (num + n == y || num * 2 == y || num * 3 == y)
            return cnt + 1;

        if (num + n <= y && visited.find(num + n) == visited.end())
        {
            q.push({num + n, cnt + 1});
            visited.insert(num + n);
        }
        if (num * 2 <= y && visited.find(num * 2) == visited.end())
        {
            q.push({num * 2, cnt + 1});
            visited.insert(num * 2);
        }
        if (num * 3 <= y && visited.find(num * 3) == visited.end())
        {
            q.push({num * 3, cnt + 1});
            visited.insert(num * 3);
        }
    }

    return answer;
}