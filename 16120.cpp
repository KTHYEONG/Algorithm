#include <iostream>
#include <stack>

using namespace std;

// PPAP
// "PPAP"�� ������ ������ �νĵǸ� �������� ó���ϱ�
int main()
{
	string input;
	cin >> input;

	stack<char> stk;
	for (int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if (c == 'P')
		{
			stk.push(c);
		}
		else
		{
			// 'A'�� ���� ���
			if (stk.size() >= 2 && input[i + 1] == 'P')
			{
				// "PPAP" -> 'P'�� ġȯ
				stk.pop();
				stk.pop();
				stk.push('P');
				i++;
			}
			else
			{
				// "PP"�� ���µ� 'A'�� ������ �߸��� ���
				cout << "NP";
				return 0;
			}
		}
	}

	// stack�� ���� 'P'�� 1���̸� �ùٸ� ���
	if (stk.size() == 1)
	{
		cout << "PPAP";
	}
	else
	{
		cout << "NP";
	}

	return 0;
}