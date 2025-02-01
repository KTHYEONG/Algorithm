#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Drawing lines
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[i] = { x, y };
	}

	sort(v.begin(), v.end());

	int minX = v[0].first, maxY = v[0].second;
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		int x = v[i].first;
		int y = v[i].second;

		// 겹치는 경우 -> 길이 확장
		if (x <= maxY)
		{
			maxY = max(maxY, y);
		}
		// 겹치지 않는 경우 -> 이전 선분의 길이 저장 및 새로운 시작 비교 기준 좌표 지정
		else
		{
			sum += maxY - minX;
			minX = x;
			maxY = y;
		}
	}

	// 마지막 선분 길이 추가
	sum += maxY - minX;

	cout << sum;

	return 0;
}