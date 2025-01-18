#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// Postfix Notation
// 연산자의 우선순위를 고려하여 stack에 push하는 것과 pop하는 것이 핵심
int main()
{
	string input;
	cin >> input;

	// 연산자의 우선순위 저장
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
			// 연산자 처리 -> 높은 우선순위 연산자 먼저 출력
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