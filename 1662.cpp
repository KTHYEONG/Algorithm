#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Compression
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	stack<pair<int, int>> stk;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ')')
		{
			int length = 0;

			while (!stk.empty())
			{
				auto top = stk.top();
				stk.pop();
				if (top.second == -1) break; // '('

				length += top.first;
			}

			// 곱해지는 숫자 k
			int k = stk.top().second;
			stk.pop();

			stk.push({ length * k, 0});
		}
		else if (s[i] == '(')
		{
			stk.push({ 0, -1 }); // '('를 구분용으로 push
		}
		else
		{
			stk.push({ 1, s[i] - '0'});
		}
	}

	int result = 0;
	while (!stk.empty())
	{
		result += stk.top().first;
		stk.pop();
	}

	cout << result;

	return 0;
}
