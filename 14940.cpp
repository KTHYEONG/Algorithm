#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Bfs(vector<vector<int>>& v, vector<vector<int>>& dist, int x, int y)
{
	queue<pair<int, int>> q;
	dist[x][y] = 0;
	q.push({ x, y });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}

			if (v[nx][ny] == 0)
			{
				continue;
			}

			if (dist[nx][ny] != -1)
			{
				continue;
			}

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx, ny });
		}
	}
}

// Easy shortest distance
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int x, y;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];

			if (v[i][j] == 2)
			{
				x = i;
				y = j;
			}
		}
	}

	vector<vector<int>> dist(n, vector<int>(m, -1));

	Bfs(v, dist, x, y);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == 0)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << dist[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}