#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Lost parentheses
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	cin >> input;

	int sum = 0;
	string num = "";
	stringstream ss(input);
	bool minusFlag = false;

	char c;
	while (ss >> c)
	{
		if (isdigit(c))
		{
			num += c;
		}
		else
		{
			int n = stoi(num);
			num = "";
			if (minusFlag)
			{
				sum -= n;
			}
			else
			{
				sum += n;
			}

			// Minus 등장 이후의 숫자는 모두 빼주기(괄호로 묶어서 작은 수로 만들기 가능)
			if (c == '-')
			{
				minusFlag = true;
			}
		}
	}

	if (!num.empty())
	{
		int n = stoi(num);
		if (minusFlag)
		{
			sum -= n;
		}
		else
		{
			sum += n;
		}
	}

	cout << sum;

	return 0;
}