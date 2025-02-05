#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> v(51, vector<int>(51, 0));
bool visited[51][51];
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void Dfs(int x, int y, int m, int n)
{
	visited[x][y] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int dx = dirX[i] + x;
		int dy = dirY[i] + y;

		if (dx < 0 || dy < 0 || dx >= m || dy >= n)
		{
			continue;
		}

		if (!visited[dx][dy] && v[dx][dy] == 1)
		{
			Dfs(dx, dy, m, n);
		}
	}
}

// Organic cabbage
// Dfs와 x, y 탐색 방향 정보(배열)를 통하여 인접한 배추를 탐색하며 해결
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n, k;
		cin >> m >> n >> k;

		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			v[x][y] = 1;
		}

		int cnt = 0;
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (!visited[j][k] && v[j][k] == 1)
				{
					Dfs(j, k, m, n);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';

		v = vector<vector<int>>(51, vector<int>(51, 0));
		memset(visited, false, sizeof(visited));
;	}

	return 0;
}