#include <iostream>
#include <stack>

using namespace std;

// Parentheses
// Stack�� '(' �� ���µ� ')'�� �Է��� ������ �߸��� ���
// ��ȣ�� ¦�� ���� �ʾƵ� �߸��� ���
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string input;
		cin >> input;

		string ans = "YES";
		stack<char> stk;
		for (char c : input)
		{
			if (c == '(')
			{
				stk.push(c);
			}
			else
			{
				if (stk.empty())
				{
					ans = "NO";
					break;
				}
				else
				{
					stk.pop();
				}
			}
		}
		// ���� ������ ���� ����
		if (!stk.empty())
			ans = "NO";

		cout << ans << '\n';
	}

	return 0;
}