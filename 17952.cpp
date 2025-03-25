#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// The work is never done!
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long ans = 0;
	stack<pair<int, int>> stk;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == 1)
		{
			int score, time;
			cin >> score >> time;

			time--;

			// 과제가 1분만에 끝나는 경우
			if (time <= 0)
			{
				ans += score;
			}
			else
			{
				stk.push({ score, time });
			}
		}
		else
		{
			if (stk.empty())
			{
				continue;
			}

			auto topElement = stk.top();
			stk.pop();

			// 과제 끝남
			if (--topElement.second <= 0)
			{
				ans += topElement.first;
			}
			// 끝나지 않은 과제는 stack에 push하여 재사용
			else
			{
				stk.push({ topElement.first, topElement.second });
			}
		}
	}

	cout << ans;

	return 0;
}