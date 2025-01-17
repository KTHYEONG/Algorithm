#include <iostream>
#include <stack>

using namespace std;

// Make it Bigger
// stack을 통해 큰 수를 계속 기록하여 작은 수는 제거하는 방식
int main()
{
	int n, k;
	cin >> n >> k;

	string num;
	cin >> num;
	
	stack<char> stk;
	for (char c : num)
	{
		while (!stk.empty() && stk.top() < c && k > 0)
		{
			stk.pop();
			k--;
		}
		stk.push(c);
	}
	while (k > 0)
	{
		stk.pop();
		k--;
	}

	stack<char> ans;
	while (!stk.empty())
	{
		ans.push(stk.top());
		stk.pop();
	}

	while (!ans.empty())
	{
		cout << ans.top();
		ans.pop();
	}


	return 0;
}