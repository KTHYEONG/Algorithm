#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Gitar String
int main()
{
	int n, m;
	cin >> n >> m;

	int minPackage = 1001, minOne = 1001;
	for (int i = 0; i < m; i++)
	{
		int package, one;
		cin >> package >> one;

		minPackage = min(minPackage, package);
		minOne = min(minOne, one);
	}

	int ans = 0;
	while (true)
	{
		if (n > 6)
		{
			ans += min(minPackage, minOne * 6);
			n -= 6;
		}
		else
		{
			ans += min(minPackage, minOne * n);
			break;
		}
	}

	cout << ans;

	return 0;
}