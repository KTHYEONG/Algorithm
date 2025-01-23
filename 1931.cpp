#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Room assignments
// 종료 시간을 기준으로 오름차순 정렬 후 그리디 탐색 수행

bool SortCmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int startTime, endTime;
		cin >> startTime >> endTime;
		v.push_back(make_pair(startTime, endTime));
	}

	sort(v.begin(), v.end(), SortCmp);

	int maxCnt = 0;
	int lastEndTime = 0;
	for (auto& meeting : v)
	{
		int startTime = meeting.first;
		int endTime = meeting.second;
		if (startTime >= lastEndTime)
		{
			maxCnt++;
			lastEndTime = endTime;
		}
	}

	cout << maxCnt;

	return 0;
}