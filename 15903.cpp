#include <iostream>
#include <queue>

using namespace std;

// Combining cards
int main()
{
	int n, m;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		pq.push(x);
	}
	
	for (int i = 0; i < m; i++)
	{
		long long first = pq.top();
		pq.pop();

		long long second = pq.top();
		pq.pop();

		long long sum = first + second;
		pq.push(sum);
		pq.push(sum);
	}
	
	long long ans = 0;
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

	cout << ans;

	return 0;
}