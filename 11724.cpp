#include <iostream>
#include <vector>

using namespace std;

void Dfs(vector<vector<bool>>& map, vector<bool>& visited, int v, int n)
{
	visited[v] = true;

	for (int i = 1; i <= n; i++)
	{
		if (!visited[i] && map[v][i])
		{
			Dfs(map, visited, i, n);
		}
	}
}

// Number of connection elements
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<bool>> map(n + 1, vector<bool>(n + 1));
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = true;
		map[y][x] = true;
	}

	int cnt = 0;
	vector<bool> visited(n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			Dfs(map, visited, i, n);
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}