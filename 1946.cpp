#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// New employee
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<int> ans;
	while (t--)
	{
		int n;
		cin >> n;

		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i].first >> v[i].second;
		}

		// 서류 성적 순으로 오름차순 정렬
		sort(v.begin(), v.end());

		int cnt = 1;
		int bestRank = v[0].second;
		for (int i = 1; i < n; i++)
		{
			if (v[i].second < bestRank)
			{
				cnt++;
				bestRank = v[i].second;
			}
		}
		ans.push_back(cnt);
	}

	for (int& element : ans)
	{
		cout << element << '\n';
	}

	return 0;
}