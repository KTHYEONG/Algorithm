#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sensor
// K���� ���߱� ��ġ�� �ϸ� K - 1���� ������� ����� ���� Ȱ��
// ������� ū �͵��� K - 1�� ��ŭ �����ϰ� ������ ������ ���ϸ� �ʿ��� �ּ� �Ÿ��� ��
int main()
{
	int n;
	cin >> n;
	
	int k;
	cin >> k;

	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	
	vector<int> distances(n - 1, 0);
	for (int i = 0; i < n - 1; i++)
	{
		distances[i] = v[i + 1] - v[i];
	}

	// �� ���� �������� ����
	sort(distances.rbegin(), distances.rend());

	int sum = 0;
	for (int i = k - 1; i < n - 1; i++)
	{
		sum += distances[i];
	}

	cout << sum;

	return 0;
}