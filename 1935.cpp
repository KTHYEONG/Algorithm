#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>

using namespace std;

// Postfix Expression2
// �ǿ����ڴ� stack�� push�ϰ� �����ڰ� ������ pop �Ͽ� ���
int main()
{
	int n;
	cin >> n;

	string input;
	cin >> input;

	vector<double> v(n, 0.0);
	for (int i = 0; i < n; i++)
	{
		double num = 0;
		cin >> num;
		v[i] = num;
	}

	stack<double> stk;
	for (int i = 0; i < input.length(); i++)
	{
		char c = input[i];
		if (c >= 'A' && c <= 'Z')
		{
			stk.push(v[c - 'A']);
		}
		else
		{
			// �ǿ����� 2�� pop
			double num1 = stk.top();
			stk.pop();
			double num2 = stk.top();
			stk.pop();
			double totalNum = 0;

			// ������ ������ ���� ���� ����
			switch (c)
			{
				case '*':
				{
					totalNum = num1 * num2;
				}
				break;
				case '/':
				{
					totalNum = num2 / num1;
				}
				break;
				case '+':
				{
					totalNum = num1 + num2;
				}
				break;
				case '-':
				{
					totalNum = num2 - num1;
				}
				break;
			}

			// ������ ���� ���ڸ� stack�� �ٽ� push�Ͽ� ������ ���꿡 ��� ���
			stk.push(totalNum);
		}
	}

	double ans = stk.top();
	cout << fixed << setprecision(2) << ans;

	return 0;
}