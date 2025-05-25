#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

// Difference sets
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int an, bn;
	cin >> an >> bn;

	set<int> a;
	for (int i = 0; i < an; i++)
	{
		int num;
		cin >> num;
		a.insert(num);
	}

	set<int> b;
	for (int i = 0; i < bn; i++)
	{
		int num;
		cin >> num;
		b.insert(num);
	}

	vector<int>ans(an + bn);
	auto it = set_difference(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
	ans.resize(it - ans.begin());

	if (ans.size() == 0)
	{
		cout << 0;
		return 0;
	}
	else
	{
		cout << ans.size() << '\n';
		for (int & element : ans)
		{
			cout << element << ' ';
		}
	}

	return 0;
}