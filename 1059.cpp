#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Good section
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int l;
	cin >> l;

	vector<int> v(l);
	for (int i = 0; i < l; i++)
	{
		cin >> v[i];
	}

	int n;
	cin >> n;

	sort(v.begin(), v.end());

	// 집합에 n이 포함된 경우
	for (int i = 0; i < l; i++)
	{
		if (v[i] == n)
		{
			cout << 0;
			return 0;
		}
	}

	int a = 0, b = 0;
	for (int i = 0; i < l; i++)
	{
		if (v[i] > n)
		{
			b = v[i];
			a = (i == 0) ? 0 : v[i - 1];
			break;
		}
	}

	int left = n - a - 1;
	int right = b - n - 1;

	cout << (left + 1) * (right + 1) - 1;

	return 0;
}