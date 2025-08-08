#include <iostream>
#include <vector>

using namespace std;

// 1
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n;
	while (cin >> n)
	{
		int rem = 1 % n;
		int len = 1;
		while (rem != 0)
		{
			rem = (rem * 10 + 1) % n;
			len++;
		}
		cout << len << '\n';
	}

	return 0;
}