#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// Sort by frequency
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, c;
	cin >> n >> c;

	map<int, pair<int, int>> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (m.find(num) == m.end())
		{
			m.insert({ num, {i, 1} });
		}
		else
		{
			m[num].second++;
		}
	}

	vector<pair<int, pair<int, int>>> v;
	for (auto& p : m)
	{
		v.push_back(p);
	}

	sort(v.begin(), v.end(), [](auto& a, auto& b) {
		if (a.second.second != b.second.second)
		return a.second.second > b.second.second;
	return a.second.first < b.second.first;
		 });

	for (auto& element : v)
	{
		for (int i = 0; i < element.second.second; i++)
		{
			cout << element.first << ' ';
		}
	}

	return 0;
}