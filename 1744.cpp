#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Tying numbers
// 양수, 음수를 따로 저장할 vector 2개를 생성
// 양수는 내림차순, 음수는 오름차순 -> 비교할 때 더 큰 값을 쉽게 찾기 위함
// 0과 1로 생기는 예외 사항을 처리하기 위하여 따로 count를 하는 변수를 지정
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

	// 양수는 내림차순, 음수는 오름차순 정렬
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
		// 음수끼리 곱하면 양수 -> 더 큰값
		if (i + 1 < negatives.size())
		{
			ans += negatives[i] * negatives[i + 1];
		}
		// 0이 없으면 해당 값 그대로 추가(0이 있으면 0과 곱한 값이 0이므로 추가 행동 x)
		else if (zeroCnt == 0)
		{
			ans += negatives[i];
		}
	}

	ans += oneCnt;

	cout << ans;

	return 0;
}