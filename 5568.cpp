#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int n, k;
vector<int> v(n);
unordered_set<string> us;

void Dfs(int depth, string cur, vector<bool>& used)
{
	if (depth == k)
	{
		us.insert(cur);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (used[i])
		{
			continue;
		}

		used[i] = true;
		Dfs(depth + 1, cur + to_string(v[i]), used);
		used[i] = false;
	}
}

// Card placement
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	v.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<bool> used(n);
	Dfs(0, "", used);

	cout << us.size();

	return 0;
}