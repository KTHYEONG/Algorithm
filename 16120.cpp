#include <iostream>
#include <stack>

using namespace std;

// PPAP
// "PPAP"의 형식이 꾸준히 인식되면 정답으로 처리하기
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
			// 'A'가 나온 경우
			if (stk.size() >= 2 && input[i + 1] == 'P')
			{
				// "PPAP" -> 'P'로 치환
				stk.pop();
				stk.pop();
				stk.push('P');
				i++;
			}
			else
			{
				// "PP"가 없는데 'A'가 나오면 잘못된 경우
				cout << "NP";
				return 0;
			}
		}
	}

	// stack에 남은 'P'가 1개이면 올바른 경우
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