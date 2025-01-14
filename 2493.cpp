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
			// ��ȣ�� ���� �� �ִ� ž�� �߰��� ���
			if (stk.top().second > topHeight)
			{
				cout << stk.top().first << ' ';
				break;
			}
			// ���̰� ���� ž�� �ʿ� x
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