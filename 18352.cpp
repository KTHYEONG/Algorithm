#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dis(300001, 300001);

void Dijkstra(vector<vector<int>>& map, int k, int x)
{
	dis[x] = 0;
	queue<int> q;
	q.push(x);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < map[cur].size(); i++)
		{
			int next = map[cur][i];
			if (dis[next] > dis[cur] + 1)
			{
				dis[next] = dis[cur] + 1;
				q.push(next);
			}
		}
	}
}

// Find cities on a specific distance
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k, x;
	cin >> n >> m >> k >> x;

	vector<vector<int>> map(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
	}

	Dijkstra(map, k, x);

	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] == k)
		{
			flag = true;
			cout << i << '\n';
		}
	}

	if (!flag)
	{
		cout << -1;
	}

	return 0;
}