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

	// ������ ���� ���� �������� ����
	sort(jewels.begin(), jewels.end());

	// ������ ���� ���� �������� ����
	sort(maxWeights.begin(), maxWeights.end());

	long long ans = 0;
	int idx = 0;
	priority_queue<int> pq;

	// ���� ���뷮�� ���� ������� ��ȸ
	for (int maxWeight : maxWeights)
	{
		// ���� ������ ������ �� �ִ� ��� ������ �켱���� ť�� �߰�
		while (idx < n && jewels[idx].first <= maxWeight)
		{
			pq.push(jewels[idx].second);
			idx++;
		}

		// �� �߿��� pq�� top�� �ִ� ���� ���� ��ġ�� ���� ���̹Ƿ� ans�� �����ְ� pop
		if (!pq.empty())
		{
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;

	return 0;
}