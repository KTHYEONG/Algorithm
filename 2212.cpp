#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sensor
// K개의 집중국 설치를 하면 K - 1개의 빈공간이 생기는 점을 활용
// 빈공간이 큰 것들을 K - 1개 만큼 제외하고 나머지 공간을 더하면 필요한 최소 거리가 됨
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

	// 빈 공간 내림차순 정렬
	sort(distances.rbegin(), distances.rend());

	int sum = 0;
	for (int i = k - 1; i < n - 1; i++)
	{
		sum += distances[i];
	}

	cout << sum;

	return 0;
}