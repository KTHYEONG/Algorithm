#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int Dfs(vector<vector<bool>>& map, vector<vector<bool>>& visited, int x, int y, int m, int n)
{
	visited[x][y] = true;

	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
		{
			continue;
		}

		if (!visited[nx][ny] && !map[nx][ny])
		{
			cnt += Dfs(map, visited, nx, ny, m, n);
		}
	}

	return cnt;
}

// Get a zone
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<bool>> map(m, vector<bool>(n));
	for (int i = 0; i < k; i++)
	{
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		
		for (int j = y0; j < y1; j++)
		{
			for (int l = x0; l < x1; l++)
			{
				map[j][l] = true;
			}
		}
	}

	int cnt = 0;
	vector<vector<bool>> visited(m, vector<bool>(n));
	vector<int> ans;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!map[i][j] && !visited[i][j])
			{
				ans.push_back(Dfs(map, visited, i, j, m, n));
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	sort(ans.begin(), ans.end());

	for (int& element : ans)
	{
		cout << element << ' ';
	}

	return 0;
}