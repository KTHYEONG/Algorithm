#include <iostream>
#include <stack>

using namespace std;

// Stable String
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int idx = 0;
	string input = "";
	while (true)
	{
		cin >> input;
		if (input[0] == '-')
		{
			break;
		}

		idx++;
		int wrongStrCnt = 0;
		stack<char> stk;

		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '{')
			{
				stk.push('{');
			}
			else if (input[i] == '}')
			{
				if (!stk.empty() && stk.top() == '{')
				{
					stk.pop();
				}
				// �߸��� ��� ��� �ٲٱ�
				else
				{
					wrongStrCnt++;
					stk.push('{');
				}
			}
		}

		// ���� '{'�� 2���� ¦��� �ùٸ� ���ڿ��� ����(2���� 1���� �����ϸ� �ذ�)
		wrongStrCnt += stk.size() / 2;

		cout << idx << ". " << wrongStrCnt << '\n';
	}

	return 0;
}