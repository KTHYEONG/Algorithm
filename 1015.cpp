#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sequence Sorting
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back({ num, i });
	}

	sort(v.begin(), v.end());

	vector<int> p(n);
	for (int i = 0; i < n; i++)
	{
		p[v[i].second] = i;
	}

	for (int& element : p)
	{
		cout << element << ' ';
	}

	return 0;
}