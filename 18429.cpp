#include <iostream>
#include <vector>

using namespace std;

int n, k;
int ans = 0;
vector<bool> visited;

void Dfs(vector<int> &v, int x, int cnt)
{
	if (x < 500)
	{
		return;
	}

	if (cnt == n)
	{
		ans++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			Dfs(v, x + v[i] - k, cnt + 1);
			visited[i] = false;
		}
	}
}
 
// Muscle loss
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	visited.assign(n, false);
	Dfs(v, 500, 0);

	cout << ans;

	return 0;
}