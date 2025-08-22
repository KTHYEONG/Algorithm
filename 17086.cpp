#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int map[51][51];
int visited[51][51];
queue<pair<int, int>> q;
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void Bfs()
{
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			{
				continue;
			}

			if (visited[nx][ny] != -1)
			{
				continue;
			}

			q.push({ nx, ny });
			visited[nx][ny] = visited[curX][curY] + 1;
		}
	}
}

// Baby Shark 2
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			visited[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				visited[i][j] = 0;
				q.push({ i, j });
			}
		}
	}

	Bfs();

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ans = max(ans, visited[i][j]);
		}
	}

	cout << ans;

	return 0;
}