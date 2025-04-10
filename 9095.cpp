#include <iostream>
#include <vector>

using namespace std;

// Add 1, 2, 3
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<int> v(12);
	v[1] = 1; v[2] = 2; v[3] = 4;
	for (int i = 4; i <= 11; i++)
	{
		v[i] = v[i - 3] + v[i - 2] + v[i - 1];
	}
	while (t--)
	{
		int n;
		cin >> n;

		cout << v[n] << '\n';
	}

	return 0;
}