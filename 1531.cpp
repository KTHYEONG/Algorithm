#include <iostream>
#include <vector>

using namespace std;

// Transparent
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(101, vector<int>(101));
	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x <= x2; x++)
		{
			for (int y = y1; y <= y2; y++)
			{
				v[x][y]++;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i < 101; i++)
	{
		for (int j = 1; j < 101; j++)
		{
			if (v[i][j] > m)
			{
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}