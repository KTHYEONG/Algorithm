#include <iostream>
#include <vector>

using namespace std;

// Colored paper
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int cnt = 0;
	vector<vector<bool>> v(100, vector<bool>(100));
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
			{
				if (!v[j][k])
				{
					cnt++;
					v[j][k] = true;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}