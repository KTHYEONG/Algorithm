#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Gas station
int main()
{
	int n;
	cin >> n;

	vector<long long> distance(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> distance[i];
	}
	
	vector<long long> cost(n);
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}

	long long ans = 0;
	long long minCost = cost[0];

	for (int i = 0; i < n - 1; i++)
	{
		ans += minCost * distance[i];
		if (cost[i + 1] < minCost)
		{
			minCost = cost[i + 1];
		}
	}

	cout << ans;

	return 0;
}