#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Square
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		vector<pair<int, int>> v;
		for (int i = 0; i < 4; i++)
		{
			int x, y;
			cin >> x >> y;

			v.push_back({ x, y });
		}

		vector<int> ans;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
			{
				ans.push_back(pow(v[i].second - v[j].second, 2) + pow(v[i].first - v[j].first, 2));
			}
		}
		
		sort(ans.begin(), ans.end());

		if (ans[0] == ans[1] && ans[1] == ans[2] && ans[2] == ans[3] && ans[4] == ans[5])
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}

	return 0;
}