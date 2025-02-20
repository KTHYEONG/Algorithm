#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Heap of absolute values
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> ans;
	priority_queue<int> pqMinus;
	priority_queue<int, vector<int>, greater<int>> pqPlus;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num != 0)
		{
			if (num < 0)
			{
				pqMinus.push(num);
			}
			else
			{
				pqPlus.push(num);
			}
		}
		else
		{
			// �켱���� ť�� ��� ����ִ� ���
			if (pqMinus.empty() && pqPlus.empty())
			{
				ans.push_back(0);
			}
			// ������ ���� �켱���� ť�� ����ִ� ���
			else if (pqMinus.empty())
			{
				ans.push_back(pqPlus.top());
				pqPlus.pop();
			}
			// ����� ���� �켱���� ť�� ����ִ� ���
			else if (pqPlus.empty())
			{
				ans.push_back(pqMinus.top());
				pqMinus.pop();
			}
			else
			{
				int negativeNum = pqMinus.top();
				int positiveNum = pqPlus.top();
				if (abs(negativeNum) <= abs(positiveNum))
				{
					ans.push_back(negativeNum);
					pqMinus.pop();
				}
				else
				{
					ans.push_back(positiveNum);
					pqPlus.pop();
				}
			}
		}
	}

	for (int element : ans)
	{
		cout << element << '\n';
	}

	return 0;
}