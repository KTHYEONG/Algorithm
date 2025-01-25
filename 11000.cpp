#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Room assignments
int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int startTime, endTime;
		cin >> startTime >> endTime;
		v.push_back({ startTime, endTime });
	}

	sort(v.begin(), v.end());
	
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	for (int i = 1; i < v.size(); i++)
	{
		// �����ϴ� �ð��� ���� ������ ������ �ð� �̻��� ��� -> ���ǽ� �̾ ���
		if (v[i].first >= pq.top())
		{
			pq.pop();
			pq.push(v[i].second);
		}
		// ���ο� ���ǽ� �ʿ��� ���
		else
		{
			pq.push(v[i].second);
		}
	}

	// ������ �ð��� ���� �켱���� ť�� ����� �ʿ��� ���ǽ� ����
	cout << pq.size();

	return 0;
}