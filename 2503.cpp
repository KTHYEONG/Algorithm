#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Number Baseball
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<bool> ans(1001, true);
	string temp;
	for (int i = 123; i <= 987; i++)
	{
		temp = to_string(i);

		if (temp[0] == temp[1] || temp[1] == temp[2] || temp[0] == temp[2]) ans[i] = false;
		if (temp[0] - '0' == 0 || temp[1] - '0' == 0 || temp[2] - '0' == 0) ans[i] = false;
	}

	int n, num, strk, ball;
	int strk_cnt, ball_cnt;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> num >> strk >> ball;

		for (int i = 123; i <= 987; i++)
		{
			strk_cnt = 0;
			ball_cnt = 0;

			if (ans[i])
			{
				string cmp1 = to_string(num);
				string cmp2 = to_string(i);

				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 3; k++)
					{
						if (j == k && cmp1[j] == cmp2[k])
						{
							strk_cnt++;
						}
						else if (j != k && cmp1[j] == cmp2[k])
						{
							ball_cnt++;
						}
					}
				}

				if (strk_cnt != strk || ball_cnt != ball)
				{
					ans[i] = false;
				}
			}
		}
	}

	int totalCnt = 0;
	for (int i = 123; i <= 987; i++)
	{
		if (ans[i])
		{
			totalCnt++;
		}
	}

	cout << totalCnt;

	return 0;
}