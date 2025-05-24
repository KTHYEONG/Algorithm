#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Eat or be eaten
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		
		vector<int> b(m);
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i] > b[j])
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}