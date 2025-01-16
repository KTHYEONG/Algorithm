#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Odeungkeunsu
// ��ū������ ������ ���� Ƚ���� ī��Ʈ �Ͽ� Ȱ���ϴ� ��� �߰�
int main()
{
	int n;
	cin >> n;

	vector<int> numCnt(1000001, 0);
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		numCnt[num]++;
		v.push_back(num);
	}

	vector<int> ans(n, 0);
	stack<int> stk;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		int curNum = v[i];
		int curNumCnt = numCnt[curNum];
		while (!stk.empty())
		{
			int compNum = stk.top();
			int compNumCnt = numCnt[compNum];
			if (curNumCnt < compNumCnt)
			{
				ans[i] = compNum;
				break;
			}
			stk.pop();
		}

		stk.push(curNum);
	}

	for (int element : ans)
	{
		if (element == 0)
			cout << -1 << ' ';
		else
			cout << element << ' ';
	}

	return 0;
}