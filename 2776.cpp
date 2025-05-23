#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Memorization King
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<int> v1(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v1[i];
		}

		sort(v1.begin(), v1.end());

		int m;
		cin >> m;

		for (int i = 0; i < m; i++)
		{
			int num;
			cin >> num;
			bool isFind = binary_search(v1.begin(), v1.end(), num);

			if (isFind)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
	}

	return 0;
}