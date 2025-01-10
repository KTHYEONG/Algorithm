#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Flip Word 2
// stack을 통해 tag의 시작('<')이 나오면 끝('>')이 나오기 까지 그대로 출력
// 일반 문자열이라면 stack에 저장 후 문자열 종료시 pop하여 출력
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
			// tag 전에 일반 문자열이 존재하는 경우
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
			// 일반 문자열 출력
			while (!stk.empty())
			{
				cout << stk.top();
				stk.pop();
			}
			cout << ' ';
		}
		else
		{
			// 일반 문자열은 push
			stk.push(c);
		}
		idx++;
	}

	// stack에 남아있는 문자 출력
	while (!stk.empty())
	{
		cout << stk.top();
		stk.pop();
	}

	return 0;
}