#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// List of Phone numbers
// 오름차순으로 정렬하여 이전 번호의 접두어 패턴이 존재하는지 확인
// 다른 방식의 풀이도 생각해보기
int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		string ans = "YES";
		vector<string> numbers(n, "0");

		for (int j = 0; j < n; j++)
		{
			cin >> numbers[j];
		}

		// 오름차순 정렬
		sort(numbers.begin(), numbers.end());

		unordered_set<string> unSet;
		bool flag = false;
		for (int j = 0; j < n; j++)
		{
			string str = "";
			for (int k = 0; k < numbers[j].length(); k++)
			{
				// 접두어 갱신
				str += numbers[j][k];
				// 접두어가 존재하는 경우 ans = NO
				if (unSet.find(str) != unSet.end())
				{
					flag = true;
					ans = "NO";
					break;
				}
			}

			if (flag)
			{
				break;
			}
			unSet.insert(numbers[j]);
		}

		cout << ans << '\n';
	}

	return 0;
}