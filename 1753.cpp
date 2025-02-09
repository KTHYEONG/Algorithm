#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int>> graph[20001];
int distances[20001];

void Solution(int startNode)
{
	fill(distances, distances + 20001, INT_MAX);
	distances[startNode] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, startNode });

	while (!pq.empty())
	{
		int curNode = pq.top().second;
		int curDistance = pq.top().first;
		pq.pop();

		// start노드에서 시작하여 현재 노드와 연결된 노드 까지의 거리 갱신
		for (int i = 0; i < graph[curNode].size(); i++)
		{
			int nextNode = graph[curNode][i].first;
			int nextDistance = curDistance + graph[curNode][i].second;
			if (distances[nextNode] > nextDistance)
			{
				pq.push({ nextDistance, nextNode });
				distances[nextNode] = nextDistance;
			}
		}
	}
}

// Shortest path
// 다익스트라 알고리즘 사용
int main()
{
	int nodesV, edgesE;
	cin >> nodesV >> edgesE;

	int startK;
	cin >> startK;

	for (int i = 0; i < edgesE; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		graph[x].push_back({y, w});
	}

	Solution(startK);

	for (int i = 1; i <= nodesV; i++)
	{
		if (distances[i] < INT_MAX)
		{
			cout << distances[i] << '\n';
		}
		else
		{
			cout << "INF" << '\n';
		}
	}

	return 0;
}