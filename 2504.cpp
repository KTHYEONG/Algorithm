#include <iostream>
#include <stack>

using namespace std;

// Value in parentheses
// Stack, 분배법칙을 통해 해결
int main()
{
	string input;
	cin >> input;

	stack<char> stk;
	int ans = 0;
	int temp = 1;
	for (int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if (c == '[' || c == '(')
		{
			stk.push(c);
			if (c == '(')
			{
				temp *= 2;
			}
			else
			{
				temp *= 3;
			}
		}
		else if (c == ']')
		{
			if (stk.empty() || stk.top() != '[')
			{
				ans = 0;
				break;
			}

			if (input[i - 1] == '[')
			{
				ans += temp;
				temp /= 3;
				stk.pop();
			}
			else
			{
				temp /= 3;
				stk.pop();
			}
		}
		else if (c == ')')
		{
			if (stk.empty() || stk.top() != '(')
			{
				ans = 0;
				break;
			}

			if (input[i - 1] == '(')
			{
				ans += temp;
				temp /= 2;
				stk.pop();
			}
			else
			{
				temp /= 2;
				stk.pop();
			}
		}
	}

	if (!stk.empty())
	{
		ans = 0;
	}

	cout << ans;

	return 0;
}