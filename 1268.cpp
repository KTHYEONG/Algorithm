#include <bits/stdc++.h>

using namespace std;

int n;
int v[1001][5];

// Selecting a Temporary Class Leader
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> v[i][j];
		}
	}

	int cnt[1001] = { 0, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			for (int k = 0; k < 5; k++)
			{
				if (v[i][k] == v[j][k])
				{
					cnt[i]++;
					break;
				}
			}
		}
	}

	int bestIdx = 0;
	for (int i = 1; i < n; i++)
	{
		if (cnt[i] > cnt[bestIdx])
		{
			bestIdx = i;
		}
	}

	cout << bestIdx + 1;

	return 0;
}