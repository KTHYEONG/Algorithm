#include <iostream>
#include <vector>

using namespace std;

void ChangeArr(vector<vector<char>>& a, int x, int y)
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (a[i][j] == '1')
			{
				a[i][j] = '0';
			}
			else
			{
				a[i][j] = '1';
			}
		}
	}
}

// Matrix
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	vector<vector<char>> b(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] != b[i][j])
			{
				ChangeArr(a, i, j);
				ans++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != b[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans;

	return 0;
}