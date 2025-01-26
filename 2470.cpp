#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Two solution
// 오름차순 정렬 후 투 포인터 이용
// 0에 가까운 값을 두 수의 합을 저장 및 비교하면서 갱신
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
		// 합이 0에 가까운 것을 비교 및 갱신
		if (abs(sum) < abs(ans))
		{
			ans = sum;
			ansLeft = v[leftIdx];
			ansRight = v[rightIdx];
		}
		
		// 포인터 이동
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