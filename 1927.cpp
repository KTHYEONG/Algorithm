#include <iostream>
#include <queue>

using namespace std;

// Minimum Heap
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}