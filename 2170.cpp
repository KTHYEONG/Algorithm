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

		// ��ġ�� ��� -> ���� Ȯ��
		if (x <= maxY)
		{
			maxY = max(maxY, y);
		}
		// ��ġ�� �ʴ� ��� -> ���� ������ ���� ���� �� ���ο� ���� �� ���� ��ǥ ����
		else
		{
			sum += maxY - minX;
			minX = x;
			maxY = y;
		}
	}

	// ������ ���� ���� �߰�
	sum += maxY - minX;

	cout << sum;

	return 0;
}