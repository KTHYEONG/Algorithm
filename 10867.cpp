#include <iostream>
#include <set>

using namespace std;

// Sorting without duplicates
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	set<int> s;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.insert(num);
	}

	for (auto it : s)
	{
		cout << it << ' ';
	}

	return 0;
}