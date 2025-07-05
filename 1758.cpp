#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Part-time worker Kang Ho
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());

	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int tip = v[i] - i;
		if (tip < 0)
		{
			continue;
		}

		sum += tip;
	}

	cout << sum;

	return 0;
}