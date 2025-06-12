#include <iostream>
#include <vector>

using namespace std;

// Numerical square
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < m; j++)
		{
			v[i][j] = input[j] - '0';
		}
	}

	int ans = 1;
	int maxNum = min(n, m);
	for (int num = 1; num <= maxNum; num++)
	{
		for (int i = 0; i <= n - num; i++)
		{
			for (int j = 0; j <= m - num; j++)
			{
				int a = v[i][j];
				int b = v[i + num - 1][j];
				int c = v[i][j + num - 1];
				int d = v[i + num - 1][j + num - 1];
				if (a == b && b == c && c == d)
				{
					ans = num;
				}
			}
		}
	}

	cout << ans * ans;

	return 0;
}