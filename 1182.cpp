#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

int sol(vector<int>& v, int sum, int k, int n, int s)
{
	if (k == n)
	{
		if (sum == s)
		{
			cnt++;
		}

		return;
	}

	sol(v, sum, k + 1, n, s);
	sol(v, sum + v[k], k + 1, n, s);
}

// Sum of a subsequence
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, s;
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sol(v, 0, 0, n, s);

	if (s == 0)
	{
		cnt--;
	}

	cout << cnt;

	return 0;
}