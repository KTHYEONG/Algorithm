#include <iostream>
#include <vector>

using namespace std;

int n;

bool Dfs(vector<vector<int>> &v, vector<vector<bool>> &visited, int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	if (visited[x][y]) return false;

	if (v[x][y] == -1) return true;

	visited[x][y] = true;
	if (v[x][y] == 0) return false;

	return Dfs(v, visited, x + v[x][y], y) || Dfs(v, visited, x, y + v[x][y]);
}

// Jump King Jelly
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	vector<vector<bool>> visited(n, vector<bool>(n));

	if (Dfs(v, visited, 0, 0))
	{
		cout << "HaruHaru";
	}
	else
	{
		cout << "Hing";
	}

	return 0;
}