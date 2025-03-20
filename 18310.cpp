#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Antenna
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

	int ans = v[(n - 1) / 2];

	cout << ans;

	return 0;
}