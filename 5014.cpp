#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Bfs(int s, int goal, int f, int u, int d)
{
	vector<int> visited(f + 1, -1);
	queue<int> q;
	q.push(s);
	visited[s] = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == goal)
		{
			return visited[cur];
		}

		for (int next : {cur + u, cur - d})
		{
			if (next >= 1 && next <= f && visited[next] == -1)
			{
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	return -1;
}

// Startlink
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	int ans = Bfs(s, g, f, u, d);
	if (ans == -1)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << ans;
	}

	return 0;
}