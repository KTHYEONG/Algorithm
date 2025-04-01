#include <iostream>
#include <deque>
#include <stack>

using namespace std;

// Alphabet Block 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	deque<char> dq;
	stack<int> stk;		// �������� ��, �� ��� �־����� ����ϱ� ���� stack

	for (int i = 0; i < n; i++)
	{
		int order;
		cin >> order;

		if (order == 3)
		{
			if (!dq.empty())
			{
				if (stk.top() == 2)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
				stk.pop();
			}
		}
		else
		{
			stk.push(order);

			char alphabet;
			cin >> alphabet;

			// �ڿ� push
			if (stk.top() == 1)
			{
				dq.push_back(alphabet);
			}
			// �տ� push
			else
			{
				dq.push_front(alphabet);
			}
		}
	}

	if (dq.empty())
	{
		cout << 0;
	}
	else
	{
		for (char& element : dq)
		{
			cout << element;
		}
	}

	return 0;
}