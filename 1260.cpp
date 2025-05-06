#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void Dfs(vector<vector<int>>& map, vector<bool>& visited, int n, int v)
{
	cout << v << ' ';
	visited[v] = true;

	for (int i = 1; i <= n; i++)
	{
		if ((map[v][i] || map[i][v]) && !visited[i])
		{
			visited[i] = true;
			Dfs(map, visited, n, i);
		}
	}
}

void Bfs(vector<vector<int>>& map, vector<bool>& visited, int n, int v)
{
	queue<int> q;
	visited[v] = true;
	q.push(v);

	while (!q.empty())
	{
		int frontNum = q.front();
		q.pop();

		cout << frontNum << ' ';

		for (int i = 1; i <= n; i++)
		{
			if ((map[frontNum][i] || map[i][frontNum]) && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

// DFS and BFS
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> map(n + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}

	vector<bool> visited(n + 1);
	Dfs(map, visited, n, v);

	cout << '\n';

	fill(visited.begin(), visited.end(), false);
	Bfs(map, visited, n, v);

	return 0;
}