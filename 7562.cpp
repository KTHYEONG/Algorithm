#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int Bfs(vector<vector<int>>& map, vector<vector<bool>>& visited, int x, int y, int gx, int gy, int l)
{
	if (x == gx && y == gy)
	{
		return 0;
	}

	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty())
	{
		auto frontNum = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = frontNum.first + dx[i];
			int ny = frontNum.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= l || ny >= l)
			{
				continue;
			}

			if (!visited[nx][ny])
			{
				visited[nx][ny] = true;
				map[nx][ny] = map[frontNum.first][frontNum.second] + 1;

				if (nx == gx && ny == gy)
				{
					return map[nx][ny];
				}

				q.push({ nx, ny });
			}
		}
	}
}

// Knight's Movement
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int l;
		cin >> l;

		vector<vector<int>> map(l, vector<int>(l));
		vector<vector<bool>> visited(l, vector<bool>(l));

		int x, y;
		cin >> x >> y;

		int goalX, goalY;
		cin >> goalX >> goalY;

		cout << Bfs(map, visited, x, y, goalX, goalY, l) << '\n';
	}

	return 0;
}