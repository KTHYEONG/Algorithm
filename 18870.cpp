#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Coordinate compression
// 오름차순 정렬 후 비교가 포인트
// 같은 숫자(v[i].second)면 이전(v[i-1].second)의 값과 동일, 더 큰 숫자면 값 갱신(by cnt)
// unique(), lower_vound()를 사용하면 더 간편해짐
int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v(n, { 0, 0 });
	for (int i = 0; i < n; i++)
	{
		v[i].first = i;
		cin >> v[i].second;
	}

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second; });

	vector<int> ans(n, 0);
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i].second == v[i - 1].second)
		{
			ans[v[i].first] = ans[v[i - 1].first];
		}
		else
		{
			ans[v[i].first] = cnt++;
		}
	}

	for (int result : ans)
	{
		cout << result << ' ';
	}

	return 0;
}