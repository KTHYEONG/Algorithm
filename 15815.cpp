#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Genius mathematician Sungpil
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	stack<int> stk;
	for (int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			stk.push((input[i] - '0'));
		}
		else
		{
			int num1 = stk.top();
			stk.pop();
			int num2 = stk.top();
			stk.pop();

			switch (input[i])
			{
				case '*':
					stk.push(num1 * num2);
					break;
				case '/':
					stk.push(num2 / num1);
					break;
				case '+':
					stk.push(num1 + num2);
					break;
				case '-':
					stk.push(num2 - num1);
					break;
			}
		}
	}

	cout << stk.top();

	return 0;
}