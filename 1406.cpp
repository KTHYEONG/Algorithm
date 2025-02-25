#include <iostream>
#include <stack>

using namespace std;

// Editor
// 2개의 Stack를 사용하여 커서 왼쪽과 오른쪽을 구분하여 데이터 관리 수행
// List를 사용하여 더 간단히 구현 가능
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string initStr;
	cin >> initStr;

	stack<char> resultStk;
	for (char c : initStr)
	{
		resultStk.push(c);
	}

	int m;
	cin >> m;

	stack<char> tempStk;
	for (int i = 0; i < m; i++)
	{
		char order;
		cin >> order;

		if (order == 'L' && !resultStk.empty())
		{
			char tempData = resultStk.top();
			resultStk.pop();
			tempStk.push(tempData);
		}
		else if (order == 'D' && !tempStk.empty())
		{
			char tempData = tempStk.top();
			tempStk.pop();
			resultStk.push(tempData);
		}
		else if (order == 'B' && !resultStk.empty())
		{
			resultStk.pop();
		}
		else if (order == 'P')
		{
			char data;
			cin >> data;

			resultStk.push(data);
		}
	}

	while (!resultStk.empty())
	{
		char tempData = resultStk.top();
		resultStk.pop();
		tempStk.push(tempData);
	}

	string ans = "";
	while (!tempStk.empty())
	{
		ans += tempStk.top();
		tempStk.pop();
	}

	cout << ans;

	return 0;
}