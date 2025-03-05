#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Rope
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

	sort(v.begin(), v.end(), greater<int>());
		
	int ans = v[0];
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		cur = v[i] * (i + 1);
		ans = max(ans, cur);
	}

	cout << ans;

	return 0;
}