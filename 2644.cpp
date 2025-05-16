#include <iostream>
#include <vector>

using namespace std;

int Dfs(vector<vector<int>>& map, vector<bool>& visited, int x, int y, int cnt)
{
	visited[x] = true;

	if (x == y)
	{
		return cnt;
	}

	for (int& element : map[x])
	{
		if (!visited[element])
		{
			int result = Dfs(map, visited, element, y, cnt + 1);
			if (result != -1)
			{
				return result;
			}
		}
	}

	return -1;
}

// Calculate the number of counts
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int p1, p2;
	cin >> p1 >> p2;

	int m;
	cin >> m;

	vector<vector<int>> map(n + 1);
	vector<bool> visited(n + 1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		map[y].push_back(x);
		map[x].push_back(y);
	}

	int ans = Dfs(map, visited, p1, p2, 0);
	cout << ans;

	return 0;
}