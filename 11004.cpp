#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// K-th number
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	cout << v[k - 1];

	return 0;
}