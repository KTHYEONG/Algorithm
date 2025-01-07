#include <iostream>
#include <stack>

using namespace std;

// Zero
// stack에 정수를 담고 0 입력시 pop 해주기
// stack이 empty가 될 때까지 pop 하여 sum에 더해주기
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