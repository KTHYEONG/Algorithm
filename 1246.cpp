#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Online Sales
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<long long> v(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	long long maxProfit = 0;
	long long bestPrice = 0;
	for (int i = 0; i < m; i++)
	{
		long long price = v[i];
		long long buyers = min(n, m - i);
		long long profit = price * buyers;

		if (profit > maxProfit || (profit == maxProfit && price < bestPrice))
		{
			maxProfit = profit;
			bestPrice = price;
		}
	}

	cout << bestPrice << ' '<< maxProfit;

	return 0;
}