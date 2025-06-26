#include <iostream>
#include <vector>

using namespace std;

// Sum of numbers 2
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int cnt = 0;
	int leftIdx = 0, rightIdx = 0;
	int sum = v[0];
	while (rightIdx < n)
	{
		if (sum == m)
		{
			cnt++;
			rightIdx++;
			if (rightIdx < n)
				sum += v[rightIdx];
		}
		else if (sum < m)
		{
			rightIdx++;
			if (rightIdx < n)
				sum += v[rightIdx];
		}
		else
		{
			sum -= v[leftIdx++];
		}
	}

	cout << cnt;

	return 0;
}