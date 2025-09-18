#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int v[4] = { 1, 5, 10 ,50 };
bool visitied[1001];
int ans = 0;

void Dfs(int cnt, int x, int cur)
{
	if (cnt == n)
	{
		if (!visitied[cur])
		{
			visitied[cur] = true;
			ans++;
		}

		return;
	}

	for (int i = x; i < 4; i++)
	{
		Dfs(cnt + 1, i, cur + v[i]);
	}
}

// Make Rome number
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	Dfs(0, 0, 0);

	cout << ans;

	return 0;
}