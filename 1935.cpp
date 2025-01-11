#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>

using namespace std;

// Postfix Expression2
// 피연산자는 stack에 push하고 연산자가 나오면 pop 하여 계산
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
			// 피연산자 2개 pop
			double num1 = stk.top();
			stk.pop();
			double num2 = stk.top();
			stk.pop();
			double totalNum = 0;

			// 연산자 종류에 따른 연산 수행
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

			// 연산이 끝난 숫자를 stack에 다시 push하여 이후의 연산에 계속 사용
			stk.push(totalNum);
		}
	}

	double ans = stk.top();
	cout << fixed << setprecision(2) << ans;

	return 0;
}