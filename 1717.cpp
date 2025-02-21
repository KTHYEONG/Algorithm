#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1000001];

int find(int x)
{
	if (x == parent[x])
	{
		return x;
	}

	parent[x] = find(parent[x]);
	return parent[x];
}

void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
	{
		return;
	}
	parent[a] = b;
}

// Representation of Sets
// 유니온 파인드 알고리즘
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i < 1000001; i++)
	{
		parent[i] = i;
	}

	vector<string> ans;
	for (int i = 0; i < m; i++)
	{
		int zeroOrOne, a, b;
		cin >> zeroOrOne >> a >> b;

		if (zeroOrOne == 0)
		{
			Union(a, b);
		}
		else
		{
			if (find(a) == find(b))
			{
				ans.push_back("YES");
			}
			else
			{
				ans.push_back("NO");
			}
		}
	}

	for (string element : ans)
	{
		cout << element << '\n';
	}

	return 0;
}