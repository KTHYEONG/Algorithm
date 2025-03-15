#include <iostream>
#include <vector>

using namespace std;

// Stock Investment
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		
		vector<long long> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		long long maxNum = 0;
		long long ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (v[i] > maxNum)
			{
				maxNum = v[i];
			}
			ans += maxNum - v[i];
		}

		cout << ans << '\n';
	}

	return 0;
}