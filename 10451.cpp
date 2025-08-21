#include <iostream>
#include <vector>

using namespace std;

int t, n;
vector<int> graph;
vector<bool> visited;

void Dfs(int x)
{
	visited[x] = true;
	if (!visited[graph[x]])
	{
		Dfs(graph[x]);
	}
}

// Permutation Cycle
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--)
	{
		cin >> n;
		graph.assign(n + 1, 0);
		visited.assign(n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			cin >> graph[i];
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				Dfs(i);
				cnt++;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}