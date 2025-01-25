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
		// 시작하는 시간이 이전 강의의 끝나는 시간 이상인 경우 -> 강의실 이어서 사용
		if (v[i].first >= pq.top())
		{
			pq.pop();
			pq.push(v[i].second);
		}
		// 새로운 강의실 필요한 경우
		else
		{
			pq.push(v[i].second);
		}
	}

	// 끝나는 시간을 담은 우선순위 큐의 사이즈가 필요한 강의실 개수
	cout << pq.size();

	return 0;
}