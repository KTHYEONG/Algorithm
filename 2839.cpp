#include <iostream>
#include <vector>

using namespace std;

// Sugar delivery
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(5001);
	v[3] = v[5] = 1;
	for (int i = 6; i <= n; i++)
	{
		if (v[i - 3])
		{
			v[i] = v[i - 3] + 1;
		}

		if (v[i - 5])
		{
			v[i] = v[i - 5] + 1;
 		}
	}

	int ans = v[n] == 0 ? -1 : v[n];

	cout << ans;

	return 0;
}