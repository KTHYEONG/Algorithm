#include <iostream>

using namespace std;

// One Number
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n < 100)
	{
		cout << n;
	}
	else
	{
		int cnt = 99;
		for (int i = 100; i <= n; i++)
		{
			int a = i / 100;
			int b = (i / 10) % 10;
			int c = i % 10;
			
			if ((a - b) == (b - c))
			{
				cnt++;
			}
		}

		cout << cnt;
	}

	return 0;
}