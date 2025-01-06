#include <iostream>
#include <stack>

using namespace std;

// Stack의 push, pop, size, empty, top -> 5개의 order 처리

int main()
{
	int n;
	cin >> n;

	stack<int> stk;
	for (int i = 0; i < n; i++)
	{
		string order;
		cin >> order;

		if (order == "push")
		{
			int num = 0;
			cin >> num;
			stk.push(num);
		}
		else if (order == "pop")
		{
			if (stk.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << stk.top() << '\n';
				stk.pop();
			}
		}
		else if (order == "size")
		{
			cout << stk.size() << '\n';
		}
		else if (order == "empty")
		{
			if (stk.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (order == "top")
		{
			if (stk.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << stk.top() << '\n';
			}
		}
	}

	return 0;
}