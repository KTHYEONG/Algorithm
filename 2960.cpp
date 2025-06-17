#include <iostream>
#include <vector>

using namespace std;

// Eratosthenes' sieve
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	int cnt = 0;
	vector<bool> v(1001);
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; i * j <= n; j++)
		{
			if (!v[i * j])
			{
				v[i * j] = true;
				cnt++;
			}

			if (cnt == k)
			{
				cout << i * j;
				return 0;
			}
		}
	}

	return 0;
}