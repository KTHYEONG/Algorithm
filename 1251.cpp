#include <iostream>
#include <algorithm>

using namespace std;

// Word Division
// 0 ~ i 까지, i ~ j 까지, i+j ~ inputLen 까지 구역을 나누고 reverse 해주기
int main()
{
	string input;
	cin >> input;

	int inputLen = input.length();
	string ansStr = "";
	for (int i = 1; i < inputLen - 2; i++)
	{
		for (int j = 1; j < inputLen - i; j++)
		{
			string firstStr = input.substr(0, i);
			string secondStr = input.substr(i, j);
			string thirdStr = input.substr(i + j);

			reverse(firstStr.begin(), firstStr.end());
			reverse(secondStr.begin(), secondStr.end());
			reverse(thirdStr.begin(), thirdStr.end());

			string totalStr = firstStr + secondStr + thirdStr;
			if (ansStr == "")
			{
				ansStr = totalStr;
			}
			ansStr = min(ansStr, totalStr);
		}
	}

	cout << ansStr;

	return 0;
}