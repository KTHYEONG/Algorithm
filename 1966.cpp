#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Printer Queue
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			q.push({ i, num });
			pq.push(num);
		}

		int cnt = 0;
		while (!pq.empty())
		{
			int idx = q.front().first;
			int secNum = q.front().second;
			q.pop();

			if (pq.top() == secNum)
			{
				cnt++;
				pq.pop();

				if (idx == m)
				{
					cout << cnt << '\n';
					break;
				}
			}
			else
			{
				q.push({ idx, secNum });
			}
		}
	}

	return 0;
}