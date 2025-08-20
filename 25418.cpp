#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int a, k;
vector<int> dist(1000001, -1);

void Bfs()
{
	dist[a] = 0;

	queue<int> q;
	q.push(a);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k)
		{
			break;
		}

		int nexts[2] = { cur + 1, cur * 2 };
		for (int nx : nexts)
		{
			if (nx > k)
			{
				continue;
			}
			if (dist[nx] != -1)
			{
				continue;
			}

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}
	}
}

// Make integer a equal to k
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> k;

	Bfs();

	cout << dist[k];

	return 0;
}