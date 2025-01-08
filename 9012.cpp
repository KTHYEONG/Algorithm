#include <iostream>
#include <stack>

using namespace std;

// Parentheses
// Stack에 '(' 가 없는데 ')'가 입력이 들어오면 잘못된 경우
// 괄호의 짝이 맞지 않아도 잘못된 경우
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
		// 최종 개수가 맞지 않음
		if (!stk.empty())
			ans = "NO";

		cout << ans << '\n';
	}

	return 0;
}