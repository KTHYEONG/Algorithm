#include <iostream>
#include <vector>

using namespace std;

// Stand in a single line
int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// �ڸ� ����
			if (v[i] == 0 && ans[j] == 0)
			{
				ans[j] = i + 1;
				break;
			}

			// �ڸ� �ǳʶٱ�
			if (ans[j] == 0)
			{
				v[i]--;
			}
		}
	}

	for (int& element : ans)
	{
		cout << element << ' ';
	}

	return 0;
}