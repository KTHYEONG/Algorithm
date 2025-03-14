#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 30
int main()
{
	string n;
	cin >> n;

	sort(n.begin(), n.end(), greater<char>());

	// 10�� ����̱� ���� ����
	if (n.find('0') == string::npos)
	{
		cout << -1;
		return 0;
	}

	int sum = 0;
	for (char c : n)
	{
		sum += c - '0';
	}

	// 3�� ����̱� ���� ����
	if (sum % 3 != 0)
	{
		cout << -1;
	}
	else
	{
		cout << n;
	}

	return 0;
}