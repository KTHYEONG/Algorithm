#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Student number
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		reverse(input.begin(), input.end());
		v[i] = input;
	}

	for (int i = 1; i <= v[0].length(); i++)
	{
		set<string> s;

		for (int j = 0; j < n; j++)
		{
			s.insert(v[j].substr(0, i));
		}

		if (s.size() == n)
		{
			cout << i;
			break;
		}
	}

	return 0;
}