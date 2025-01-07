#include <iostream>
#include <stack>

using namespace std;

// Zero
// stack�� ������ ��� 0 �Է½� pop ���ֱ�
// stack�� empty�� �� ������ pop �Ͽ� sum�� �����ֱ�
int main()
{
	int k;
	cin >> k;

	int sum = 0;
	stack<int> stk;
	for (int i = 0; i < k; i++)
	{
		int money;
		cin >> money;
		if (money != 0)
		{
			stk.push(money);
		}
		else
		{
			if (!stk.empty())
			{
				stk.pop();
			}
		}
	}

	while (!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}

	cout << sum;
	
	return 0;
}