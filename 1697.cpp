#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void Bfs(int n, int k)
{
    vector<int> dist(100001, -1);
    queue<int> q;

    dist[n] = 0;
    q.push(n);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == k)
        {
            cout << dist[current];
            return;
        }

        for (int next : {current - 1, current + 1, current * 2})
        {
            if (next >= 0 && next <= 100000 && dist[next] == -1)
            {
                dist[next] = dist[current] + 1;
                q.push(next);
            }
        }
    }
}

// Hide and seek
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	Bfs(n, k);

	return 0;
}