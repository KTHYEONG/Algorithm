#include <iostream>
#include <list>

using namespace std;

// KeyLogger
// '<', '>' Ŀ�� �����ӿ� ���� ��ġ ���� �ʿ�
// '-' �齺���̽��� ���� ��� ���� �ʿ�
int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string passWord;
		cin >> passWord;

		list<char> passWordList;
		auto cursor = passWordList.begin();

		for (int j = 0; j < passWord.length(); j++)
		{
			char c = passWord[j];
			// Ŀ�� �������� �̵�
			if (c == '<')
			{
				if (cursor != passWordList.begin())
				{
					cursor = prev(cursor);
				}
			}
			// Ŀ�� ������ �̵�
			else if (c == '>')
			{
				if (cursor != passWordList.end())
				{
					cursor = next(cursor);
				}
			}
			// �齺���̽� �Է�
			else if (c == '-')
			{
				if (cursor != passWordList.begin())
				{
					cursor = passWordList.erase(prev(cursor));
				}
			}
			else
			{
				cursor = passWordList.insert(cursor, c);
				cursor = next(cursor);
			}
		}

		for (char c : passWordList)
		{
			cout << c;
		}
		cout << '\n';
	}



	return 0;
}