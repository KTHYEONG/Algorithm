#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// Postfix Notation
// �������� �켱������ ����Ͽ� stack�� push�ϴ� �Ͱ� pop�ϴ� ���� �ٽ�
int main()
{
	string input;
	cin >> input;

	// �������� �켱���� ����
	unordered_map<char, int> priority =
	{
		{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}
	};

	stack<char> stk;
	for (char c : input)
	{
		if (c >= 'A' && c <= 'Z')
		{
			cout << c;
		}
		else if (c == '(')
		{
			stk.push(c);
		}
		else if (c == ')')
		{
			while (!stk.empty() && stk.top() != '(')
			{
				cout << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else
		{
			// ������ ó�� -> ���� �켱���� ������ ���� ���
			while (!stk.empty() && stk.top() != '(' && priority[stk.top()] >= priority[c])
			{
				cout << stk.top();
				stk.pop();
			}
			stk.push(c);
		}
	}

	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}