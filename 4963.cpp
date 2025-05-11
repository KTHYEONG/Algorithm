#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void Bfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int h, int w, int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty())
	{
		auto temp = q.front();
		int cy = temp.first;
		int cx = temp.second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;

			if (!visited[ny][nx] && map[ny][nx] == 1)
			{
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

// Numeber of islands
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}

		vector<vector<int>> map(h, vector<int>(w));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		vector<vector<bool>> visited(h, vector<bool>(w));

		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visited[i][j] && map[i][j] == 1)
				{
					Bfs(map, visited, h, w, i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}