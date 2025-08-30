#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, s;
vector<int> v;
vector<bool> visited;

int Bfs(int x)
{
	queue<int> q;
	q.push(x);
	visited[x] = true;

	int cnt = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		int nx1 = cur + v[cur];
		int nx2 = cur - v[cur];

		if (1 <= nx1 && nx1 <= n && !visited[nx1])
		{
			visited[nx1] = true;
			q.push(nx1);
			++cnt;
		}
		if (1 <= nx2 && nx2 <= n && !visited[nx2])
		{
			visited[nx2] = true;
			q.push(nx2);
			++cnt;
		}
	}

	return cnt;
}

// Jump jump
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	v.assign(n + 1, 0);
	visited.assign(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	cin >> s;

	cout << Bfs(s);

	return 0;
}