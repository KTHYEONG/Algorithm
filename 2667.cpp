#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ans;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int Dfs(vector<vector<int>>& v, vector<vector<bool>>& visited, int x, int y, int n)
{
	visited[x][y] = true;
	int cnt = 1;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
		{
			continue;
		}

		if (!visited[nx][ny] && v[nx][ny] == 1)
		{
			cnt += Dfs(v, visited, nx, ny, n);
		}
	}

	return cnt;
}

// Numbering house
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = input[j] - '0';
		}
	}

	vector<vector<bool>> visited(n, vector<bool>(n));
	int totalCnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && map[i][j] == 1)
			{
				ans.push_back(Dfs(map, visited, i, j, n));
				totalCnt++;
			}
		}
	}

	cout << totalCnt << '\n';

	sort(ans.begin(), ans.end());

	for (int& element : ans)
	{
		cout << element << '\n';
	}

	return 0;
}