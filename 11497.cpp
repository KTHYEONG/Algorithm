#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Jumping over logs
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

		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());

		vector<int> arranged(n);
		int left = 0, right = n - 1;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				arranged[left++] = v[i];
			}
			else
			{
				arranged[right--] = v[i];
			}
		}

		int maxDiff = 0;
		for (int i = 0; i < n; i++)
		{
			int diff = abs(arranged[i] - arranged[(i + 1) % n]);
			maxDiff = max(maxDiff, diff);
		}

		cout << maxDiff << '\n';
	}

	return 0;
}