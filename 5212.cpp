#include <bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char>> v;
vector<pair<int, int>> ans;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// Global Warming
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;
	v.resize(r, vector<char>(c, '.'));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> v[i][j];
		}
	}

	// ¹Ù´Ù·Î ¹Ù²ð °÷ Å½»ö
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (v[i][j] == 'X')
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int nx = dx[k] + i;
					int ny = dy[k] + j;

					if (nx < 0 || ny < 0 || nx >= r || ny >= c)
					{
						cnt++;
						continue;
					}

					if (v[nx][ny] == '.')
					{
						cnt++;
					}
				}

				if (cnt >= 3)
				{
					ans.push_back({ i, j });
				}
			}
		}
	}

	// ¶¥ -> ¹Ù´Ù·Î º¯È¯
	for (int i = 0; i < ans.size(); i++)
	{
		v[ans[i].first][ans[i].second] = '.';
	}

	int min_r = r, max_r = -1, min_c = c, max_c = -1;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (v[i][j] == 'X')
			{
				min_r = min(min_r, i);
				max_r = max(max_r, i);
				min_c = min(min_c, j);
				max_c = max(max_c, j);
			}
		}
	}

	for (int i = min_r; i <= max_r; i++)
	{
		for (int j = min_c; j <= max_c; j++)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}

	return 0;
}