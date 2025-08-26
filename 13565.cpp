#include <iostream>
#include <algorithm>

using namespace std;

int m, n;
int map[1001][1001];
bool visited[1001][1001];
bool flag = false;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Dfs(int x, int y)
{
	visited[x][y] = true;
	if (x == m - 1)
	{
		flag = true;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || ny >= n)
		{
			continue;
		}

		if (map[nx][ny] != 0)
		{
			continue;
		}

		if (visited[nx][ny])
		{
			continue;
		}

		Dfs(nx, ny);
	}
}

// Percolate
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			map[i][j] = c - '0';
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[0][i] && map[0][i] == 0)
		{
			Dfs(0, i);
			if (flag)
			{
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";

	return 0;
}