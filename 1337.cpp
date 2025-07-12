#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Correct arrangement
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int minAdd = 5;
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = i; j < n; j++)
		{
			if (v[j] - v[i] < 5)
			{
				cnt++;
			}
			else
			{
				break;
			}
		}

		minAdd = min(minAdd, 5 - cnt);
	}

	cout << minAdd;

	return 0;
}