#include <iostream>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

void Bfs(int a, int b)
{
	queue < pair<long long, long long >> q;
	q.push({ a, 1 });

	unordered_set<long long> visited;
	visited.insert(a);

	while (!q.empty())
	{
		pair<long long, long long> frontNum = q.front();
		q.pop();

		long long condA = frontNum.first * 2;
		long long condB = frontNum.first * 10 + 1;

		if (condA == b || condB == b)
		{
			cout << frontNum.second + 1;
			return;
		}

		if (condA <= b && visited.find(condA) == visited.end())
		{
			q.push({ condA, frontNum.second + 1 });
			visited.insert(condA);
		}
		if (condB <= b && visited.find(condB) == visited.end())
		{
			q.push({ condB, frontNum.second + 1 });
			visited.insert(condB);
		}
	}

	cout << -1;
}

// A -> B
int main()
{
	int a, b;
	cin >> a >> b;

	Bfs(a, b);

	return 0;
}