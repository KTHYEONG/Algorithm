#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Sum of two numbers
// 오름차순 정렬 후 투 포인터 이용
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

	int x;
	cin >> x;

	int leftIdx = 0, rightIdx = n - 1;
	int cnt = 0;
	while (leftIdx < rightIdx)
	{
		int leftNum = v[leftIdx];
		int rightNum = v[rightIdx];
		int sum = leftNum + rightNum;
		
		if (sum == x)
		{
			cnt++;
			leftIdx++;
		}
		else if (sum < x)
		{
			leftIdx++;
		}
		else
		{
			rightIdx--;
		}
	}

	cout << cnt;

	return 0;
}