#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// List of Phone numbers
// ������������ �����Ͽ� ���� ��ȣ�� ���ξ� ������ �����ϴ��� Ȯ��
// �ٸ� ����� Ǯ�̵� �����غ���
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

		// �������� ����
		sort(numbers.begin(), numbers.end());

		unordered_set<string> unSet;
		bool flag = false;
		for (int j = 0; j < n; j++)
		{
			string str = "";
			for (int k = 0; k < numbers[j].length(); k++)
			{
				// ���ξ� ����
				str += numbers[j][k];
				// ���ξ �����ϴ� ��� ans = NO
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