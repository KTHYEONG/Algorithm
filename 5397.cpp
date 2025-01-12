#include <iostream>
#include <list>

using namespace std;

// KeyLogger
// '<', '>' 커서 움직임에 따른 위치 조절 필요
// '-' 백스페이스에 따른 요소 제거 필요
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
			// 커서 왼쪽으로 이동
			if (c == '<')
			{
				if (cursor != passWordList.begin())
				{
					cursor = prev(cursor);
				}
			}
			// 커서 오른쪽 이동
			else if (c == '>')
			{
				if (cursor != passWordList.end())
				{
					cursor = next(cursor);
				}
			}
			// 백스페이스 입력
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