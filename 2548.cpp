#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Representative natural number
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

	cout << v[(n - 1) / 2];

	return 0;
}