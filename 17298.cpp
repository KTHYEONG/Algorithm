#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Okeunsu
// 2493번 탑 문제와 비슷
// stack에 담은 숫자 중 필요 없는 수(작은 수)는 제거하면서 비교하는 방식
int main()
{
	int n;
	cin >> n;

	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> ans(n, -1);
	stack<int> stk;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		int curNum = v[i];
		while (!stk.empty())
		{
			int topNum = stk.top();
			if (curNum < topNum)
			{
				ans[i] = topNum;
				break;
			}
			stk.pop();
		}

		stk.push(curNum);
	}

	for (int element : ans)
	{
		cout << element << ' ';
	}

	return 0;
}