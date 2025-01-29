#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Jewel Thief
int main()
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> jewels(n);
	for (int i = 0; i < n; i++)
	{
		cin >> jewels[i].first >> jewels[i].second;
	}

	vector<int> maxWeights(k);
	for (int i = 0; i < k; i++)
	{
		cin >> maxWeights[i];
	}

	// 보석을 무게 기준 오름차순 정렬
	sort(jewels.begin(), jewels.end());

	// 가방을 무게 기준 오름차순 정렬
	sort(maxWeights.begin(), maxWeights.end());

	long long ans = 0;
	int idx = 0;
	priority_queue<int> pq;

	// 작은 수용량을 가진 가방부터 순회
	for (int maxWeight : maxWeights)
	{
		// 현재 가방이 수용할 수 있는 모든 보석을 우선순위 큐에 추가
		while (idx < n && jewels[idx].first <= maxWeight)
		{
			pq.push(jewels[idx].second);
			idx++;
		}

		// 그 중에서 pq의 top에 있는 값이 가장 가치가 높은 값이므로 ans에 더해주고 pop
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;

	return 0;
}