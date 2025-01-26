#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Two solution
// �������� ���� �� �� ������ �̿�
// 0�� ����� ���� �� ���� ���� ���� �� ���ϸ鼭 ����
int main()
{
	int n;
	cin >> n;

	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int leftIdx = 0;
	int rightIdx = n - 1;
	long long ans = LLONG_MAX;
	int ansLeft = 0, ansRight = 0;
	while (leftIdx < rightIdx)
	{
		long long sum = v[leftIdx] + v[rightIdx];
		// ���� 0�� ����� ���� �� �� ����
		if (abs(sum) < abs(ans))
		{
			ans = sum;
			ansLeft = v[leftIdx];
			ansRight = v[rightIdx];
		}
		
		// ������ �̵�
		if (sum < 0)
		{
			leftIdx++;
		}
		else if (sum > 0)
		{
			rightIdx--;
		}
		else
		{
			break;
		}
	}

	cout << ansLeft << ' ' << ansRight;

	return 0;
}