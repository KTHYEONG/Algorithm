#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Flip Word 2
// stack�� ���� tag�� ����('<')�� ������ ��('>')�� ������ ���� �״�� ���
// �Ϲ� ���ڿ��̶�� stack�� ���� �� ���ڿ� ����� pop�Ͽ� ���
int main()
{
	string s;
	getline(cin, s);

	int idx = 0;
	stack<char> stk;
	while (idx < s.length())
	{
		char c = s[idx];
		// Tag
		if (c == '<')
		{
			// tag ���� �Ϲ� ���ڿ��� �����ϴ� ���
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}

			while (true)
			{
				cout << c;
				if (c == '>')
				{
					break;
				}
				c = s[++idx];
			}
		}
		else if (c == ' ')
		{
			// �Ϲ� ���ڿ� ���
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}
			cout << ' ';
		}
		else
		{
			// �Ϲ� ���ڿ��� push
			stk.push(c);
		}
		idx++;
	}

	// stack�� �����ִ� ���� ���
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}