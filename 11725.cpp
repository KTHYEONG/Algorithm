#include <iostream>
#include <vector>

using namespace std;

vector<int> ans(100001);

void Dfs(vector<vector<int>>& map, vector<bool>& visited, int v)
{
	visited[v] = true;
	for (int next : map[v])
	{
		if (!visited[next])
		{
			ans[next] = v;
			Dfs(map, visited, next);
		}
	}
}

// Find the parent of a tree
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> map(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;

		map[x].push_back(y);
		map[y].push_back(x);
	}

	vector<bool> visited(n + 1);
	Dfs(map, visited, 1);

	for (int i = 2; i <= n; i++)
	{
		cout << ans[i] << '\n';
	}

	return 0;
}