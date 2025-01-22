#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Coordinate compression
// �������� ���� �� �񱳰� ����Ʈ
// ���� ����(v[i].second)�� ����(v[i-1].second)�� ���� ����, �� ū ���ڸ� �� ����(by cnt)
// unique(), lower_vound()�� ����ϸ� �� ��������
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