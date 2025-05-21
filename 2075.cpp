#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// Nth largest number
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 0; i < n * n; i++)
	{
		int x;
		cin >> x;

		pq.push(x);
		if (pq.size() > n)
		{
			pq.pop();
		}
	}

	cout << pq.top();

	return 0;
}