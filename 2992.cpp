#include <iostream>
#include <algorithm>

using namespace std;

// Small numbers that are also large
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string x;
	cin >> x;

	string t = x;
	if (next_permutation(t.begin(), t.end()))
	{
		cout << t << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}

	return 0;
}