#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int box[101][101][101];
int dirZ[2] = { 1, -1 };
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void Bfs(queue<pair<int, pair<int, int>>>& q, int m, int n, int h)
{
	while (!q.empty())
	{
		auto qFront = q.front();
		int z = qFront.first;
		int x = qFront.second.first;
		int y = qFront.second.second;
		q.pop();

		// 가로, 세로 탐색
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dirX[i];
			int ny = y + dirY[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			{
				continue;
			}

			if (box[z][nx][ny] == 0)
			{
				box[z][nx][ny] = box[z][x][y] + 1;
				q.push({ z, {nx, ny} });
			}
		}

		// 위, 아래 탐색
		for (int i = 0; i < 2; i++)
		{
			int nz = z + dirZ[i];

			if (nz < 0 || nz >= h)
			{
				continue;
			}

			if (box[nz][x][y] == 0)
			{
				box[nz][x][y] = box[z][x][y] + 1;
				q.push({ nz, {x, y} });
			}
		}
	}
}

// Tomato
// 7576번 문제의 확장 -> 위, 아래 탐색 추가 -> 3차원 배열을 통해 표현
int main()
{
	int m, n, h;
	cin >> m >> n >> h;

	queue<pair<int, pair<int, int>>> q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					q.push({ i, {j, k} });
				}
			}
		}
	}

	Bfs(q, m, n, h);

	int ans = -1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
				ans = max(ans, box[i][j][k]);
			}
		}
	}

	cout << ans - 1;

	return 0;
}