#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int cnt = 0;
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void Bfs(vector<vector<int>>& box, queue<pair<int, int>>& q, int m, int n)
{
	while (!q.empty())
	{
		int frontX = q.front().first;
		int frontY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = frontX + dirX[i];
			int ny = frontY + dirY[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			{
				continue;
			}

			if (box[nx][ny] == 0)
			{
				box[nx][ny] = box[frontX][frontY] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

// Tomato
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> box(m, vector<int>(n, 0));
	queue<pair<int, int>> q;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> box[i][j];

			if (box[i][j] == 1)
			{
				q.push({ i, j });
			}
		}
	}

	Bfs(box, q, m, n);

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// Bfs 끝난 후 익지 않은 토마토가 있는 경우
			if (box[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			ans = max(ans, box[i][j]);
		}
	}

	cout << ans - 1;

	return 0;
}