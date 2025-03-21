#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Repairman HangSeung
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, l;
	cin >> n >> l;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int ans = 0;
	int i, j;
	for (i = 0; i < n;)
	{
		for (j = i + 1; j < n; j++)
		{
			if (v[j] - v[i] > l - 1)
			{
				break;
			}
		}

		i = j;
		ans++;
	}

	cout << ans;

	return 0;
}

//while (i < n)
//{
//	int coverUntil = v[i] + l - 1;
//	ans++;
//	i++;
//
//	while (i < n && v[i] <= coverUntil)
//	{
//		i++;
//	}
//}