#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Tying numbers
// ���, ������ ���� ������ vector 2���� ����
// ����� ��������, ������ �������� -> ���� �� �� ū ���� ���� ã�� ����
// 0�� 1�� ����� ���� ������ ó���ϱ� ���Ͽ� ���� count�� �ϴ� ������ ����
int main()
{
	int n;
	cin >> n;

	vector<int> positives, negatives;
	int zeroCnt = 0, oneCnt = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (num > 1)
		{
			positives.push_back(num);
		}
		else if (num == 1)
		{
			oneCnt++;
		}
		else if (num < 0)
		{
			negatives.push_back(num);
		}
		else
		{
			zeroCnt++;
		}
	}

	// ����� ��������, ������ �������� ����
	sort(positives.rbegin(), positives.rend());
	sort(negatives.begin(), negatives.end());

	int ans = 0;
	for (int i = 0; i < positives.size(); i+=2)
	{
		if (i + 1 < positives.size())
		{
			ans += positives[i] * positives[i + 1];
		}
		else
		{
			ans += positives[i];
		}
	}

	for (int i = 0; i < negatives.size(); i += 2)
	{
		// �������� ���ϸ� ��� -> �� ū��
		if (i + 1 < negatives.size())
		{
			ans += negatives[i] * negatives[i + 1];
		}
		// 0�� ������ �ش� �� �״�� �߰�(0�� ������ 0�� ���� ���� 0�̹Ƿ� �߰� �ൿ x)
		else if (zeroCnt == 0)
		{
			ans += negatives[i];
		}
	}

	ans += oneCnt;

	cout << ans;

	return 0;
}