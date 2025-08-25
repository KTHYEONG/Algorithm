#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
char map[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool visited[101][101];

void Bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	char c = map[x][y];
	visited[x][y] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			{
				continue;
			}

			if (visited[nx][ny])
			{
				continue;
			}

			if (map[nx][ny] != c)
			{
				continue;
			}

			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

// red-green color blindness
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	int cnt1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				Bfs(i, j);
				cnt1++;
			}
		}
	}

	cout << cnt1 << ' ';

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'R')
			{
				map[i][j] = 'G';
			}
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				Bfs(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt2;

	return 0;
}