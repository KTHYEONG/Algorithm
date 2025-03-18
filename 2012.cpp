#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Numbering
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long ans = 0;
	for (int i = 0; i < v.size(); i++)
	{
		ans += abs(v[i] - (i + 1));
	}

	cout << ans;

	return 0;
}