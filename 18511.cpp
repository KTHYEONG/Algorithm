#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, ans;
vector<int> v(k);

void Sol(int num)
{
	if (num > n)
	{
		return;
	}

	ans = max(ans, num);

	for (int i = 0; i < k; i++)
	{
		Sol(num * 10 + v[i]);
	}
}

// Building large numbers
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	v.resize(k);
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
	}

	ans = 0;
	Sol(0);

	cout << ans;

	return 0;
}