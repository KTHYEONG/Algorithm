#include <iostream>
#include <string.h>

using namespace std;

int picture[501][501];
bool visited[501][501];
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };
int maxWidth = 0;	// maxWidth -> 그림 중 최대 넓이 갱신

int Dfs(int n, int m, int x, int y)
{
	visited[x][y] = true;

	int width = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dirX[i];
		int ny = y + dirY[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
		{
			continue;
		}

		if (!visited[nx][ny] && picture[nx][ny] == 1)
		{
			width += Dfs(n, m, nx, ny);
		}
	}

	return width;
}

// Picture
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> picture[i][j];
		}
	}

	memset(visited, false, sizeof(visited));

	// cnt -> 그림의 개수 카운트(Dfs 탐색이 한 번 끝나면 그림 1개 탐색 완료 의미)
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j] && picture[i][j] == 1)
			{
				int width = Dfs(n, m, i, j);
				maxWidth = max(maxWidth, width);
				cnt++;
			}
		}
	}

	cout << cnt << '\n' << maxWidth;

	return 0;
}