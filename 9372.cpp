#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int t;
int n, m;
vector<vector<int>> map;
vector<bool> visited;

int Bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = true;

	int cnt = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nx : map[cur])
		{
			if (!visited[nx])
			{
				visited[nx] = true;
				q.push(nx);
				cnt++;
			}
		}
	}

	return cnt;
}

// Sanggeun's Journey
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		map.assign(n + 1, {});
		visited.assign(n + 1, false);

		for (int j = 0; j < m; j++)
		{
			int a, b;
			cin >> a >> b;
			map[a].push_back(b);
			map[b].push_back(a);
		}

		cout << Bfs(1) << '\n';
	}

	return 0;
}