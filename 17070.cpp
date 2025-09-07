#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int v[17][17];
int ans = 0;

void Dfs(int x, int y, int dir)
{
	if (x == n && y == n)
	{
		ans++;
		return;
	}

	// 가로 이동
	if (dir == 0 || dir == 2)
	{
		int nx = x, ny = y + 1;
		if (ny <= n && v[nx][ny] == 0)
		{
			Dfs(nx, ny, 0);
		}
	}

	// 세로 이동
	if (dir == 1 || dir == 2)
	{
		int nx = x + 1, ny = y;
		if (nx <= n && v[nx][ny] == 0)
		{
			Dfs(nx, ny, 1);
		}
	}

	// 대각 이동
	int nx = x + 1, ny = y + 1;
	if (nx <= n && ny <= n && v[x][y + 1] == 0 && v[x + 1][y] == 0 && v[nx][ny] == 0)
	{
		Dfs(nx, ny, 2);
	}
}

// Pipe
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> v[i][j];
		}
	}

	Dfs(1, 2, 0);

	cout << ans;

	return 0;
}