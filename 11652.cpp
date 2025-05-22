#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Card
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long >v;
	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long ans = v[0];
	int cnt = 1;
	int maxCnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i] == v[i - 1])
		{
			cnt++;
		}
		else
		{
			cnt = 1;
		}

		if (maxCnt < cnt)
		{
			maxCnt = cnt;
			ans = v[i];
		}
	}

	cout << ans;

	return 0;
}