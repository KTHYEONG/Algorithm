#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Creating a Triangle
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

	for (int i = n - 1; i >= 2; i--)
	{
		if (v[i - 2] + v[i - 1] > v[i])
		{
			cout << v[i - 2] + v[i - 1] + v[i];
			return 0;
		}
	}

	cout << -1;

	return 0;
}