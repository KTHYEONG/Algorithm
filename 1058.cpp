#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int ans = 0;
vector<string> v(n);

void Bfs(int x)
{
	vector<int> dist(n, -1);
	queue<int> q;
	q.push(x);
	dist[x] = 0;

	int friends = 0;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (dist[cur] >= 2)
		{
			continue;
		}

		for (int i = 0; i < n; i++)
		{
			if (v[cur][i] == 'Y' && dist[i] == -1)
			{
				dist[i] = dist[cur] + 1;
				if (dist[i] <= 2)
				{
					friends++;
				}
				q.push(i);
			}
		}
	}

	ans = max(ans, friends);
}

// Friend
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < n; i++)
	{
		Bfs(i);
	}

	cout << ans;

	return 0;
}