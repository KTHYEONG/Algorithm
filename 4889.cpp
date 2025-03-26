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
				// 잘못된 경우 모양 바꾸기
				else
				{
					wrongStrCnt++;
					stk.push('{');
				}
			}
		}

		// 남은 '{'는 2개씩 짝지어서 올바른 문자열로 수정(2개중 1개만 수정하면 해결)
		wrongStrCnt += stk.size() / 2;

		cout << idx << ". " << wrongStrCnt << '\n';
	}

	return 0;
}