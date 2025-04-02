#include <iostream>
#include <stack>

using namespace std;

// Polar bears rip off parentheses
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	string input;
	cin >> input;

	int ans = 0;
	stack<char> stk;
	for (int i = 0; i < input.length(); i++)
	{
		if (stk.empty())
		{
			stk.push(input[i]);
		}
		else
		{
			if (stk.top() == '(')
			{
				if (input[i] == ')')
				{
					stk.pop();
				}
				else
				{
					stk.push(input[i]);
				}
			}
			else
			{
				if (input[i] == '(')
				{
					stk.pop();
				}
				else
				{
					stk.push(input[i]);
				}
			}
		}

		ans = max(ans, (int)stk.size());
	}

	if (!stk.empty())
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}

	return 0;
}