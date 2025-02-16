#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

vector<pair<int, int>> graph[1001];
vector<int> costs;

void Solution(int start, int n)
{
	costs.assign(n + 1, INT_MAX);
	costs[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int curNode = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (curCost > costs[curNode])
		{
			continue;
		}

		for (int i = 0; i < graph[curNode].size(); i++)
		{
			int nextNode = graph[curNode][i].first;
			int nextCost = curCost + graph[curNode][i].second;
			if (costs[nextNode] > nextCost)
			{
				pq.push({ nextCost, nextNode });
				costs[nextNode] = nextCost;
			}
		}
	}
}

// Finding the minimum cost
// 다익스트라 알고리즘 사용
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back({ y, w });
	}

	int start, goal;
	cin >> start >> goal;

	Solution(start, n);

	cout << costs[goal];

	return 0;
}
