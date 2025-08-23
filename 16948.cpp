#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int r1, c1, r2, c2;
int map[201][201];
int dist[201][201];
int dx[6] = { -2, -2, 0, 0, 2, 2 };
int dy[6] = { -1, 1, -2, 2, -1, 1 };

void Bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	for (int i = 0; i < 201; i++)
	{
		for (int j = 0; j < 201; j++)
		{
			dist[i][j] = -1;
		}
	}
	dist[x][y] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		
		for (int i = 0; i < 6; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			{
				continue;
			}

			if (dist[nx][ny] != -1)
			{
				continue;
			}

			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}
}

// Death Knight
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	Bfs(r1, c1);

	if (dist[r2][c2] == -1)
	{
		cout << -1;
	}
	else
	{
		cout << dist[r2][c2];
	}

	return 0;
}