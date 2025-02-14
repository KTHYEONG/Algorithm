#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool visited[101][101] = { false };
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void Dfs(vector<vector<int>>& v, int n, int x, int y, int height)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dirX[i];
		int ny = y + dirY[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
		{
			continue;
		}

		// 방문 x + 잠기지 않는 영역 -> 안전한 영역
		if (!visited[nx][ny] && v[nx][ny] > height)
		{
			Dfs(v, n, nx, ny, height);
		}
	}
}

// Safety zone
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int maxNum = 0;
	vector<vector<int>> areas(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> areas[i][j];
			maxNum = max(maxNum, areas[i][j]);
		}
	}

	int ans = 1;
	// 낮은 높이부터 최대 높이까지 안전한 영역 확인
	for (int height = 0; height <= maxNum; height++)
	{
		memset(visited, false, sizeof(visited));

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j] && areas[i][j] > height)
				{
					Dfs(areas, n, i, j, height);
					cnt++;
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}