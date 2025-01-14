#include <iostream>
#include <stack>

using namespace std;

// Top
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	stack<pair<int, int>> stk;
	for (int i = 0; i < n; i++)
	{
		int topHeight;
		cin >> topHeight;

		while (!stk.empty())
		{
			// 신호를 받을 수 있는 탑을 발견한 경우
			if (stk.top().second > topHeight)
			{
				cout << stk.top().first << ' ';
				break;
			}
			// 높이가 낮은 탑은 필요 x
			stk.pop();
		}

		if (stk.empty())
		{
			cout << 0 << ' ';
		}
		stk.push({ i + 1, topHeight });
	}

	return 0;
}