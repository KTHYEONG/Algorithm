#include <Bits/stdc++.h>

using namespace std;

int n, d;

// Number of Occurrences
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> d;

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (temp)
		{
			if (temp % 10 == d)
			{
				cnt++;
			}
			temp /= 10;
		}
	}

	cout << cnt;

	return 0;
}