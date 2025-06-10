#include <iostream>
#include <queue>

using namespace std;

// The Josephus Problem
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	cout << '<';

	int cnt = 1;
	while (q.size() != 1)
	{
		if (cnt != k)
		{
			q.push(q.front());
			q.pop();
			cnt++;
		}
		else
		{
			cout << q.front() << ", ";
			q.pop();
			cnt = 1;
		}
	}

	cout << q.front() << '>';

	return 0;
}