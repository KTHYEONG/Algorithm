#include <bits/stdc++.h>

using namespace std;

int p, t;

// Line up
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> p;

	while (p--)
	{
		cin >> t;

		vector<int> v(20);
		for (int i = 0; i < 20; i++)
		{
			cin >> v[i];
		}

		int cnt = 0;
		for (int i = 1; i < 20; i++)
		{
			int key = v[i];
			int j = i - 1;
			while (j >= 0 && v[j] > key)
			{
				v[j + 1] = v[j];
				j--;
				cnt++;
			}
			v[j + 1] = key;
		}

		cout << t << ' ' << cnt << '\n';
	}

	return 0;
}