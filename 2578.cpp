#include <iostream>
#include <vector>

using namespace std;

int cond(vector<vector<bool>>& check)
{
	int cnt = 0;

	// 세로
	for (int i = 0; i < 5; i++)
	{
		if (check[i][0] && check[i][1] && check[i][2] && check[i][3] && check[i][4])
		{
			cnt++;
		}
	}

	// 가로
	for (int i = 0; i < 5; i++)
	{
		if (check[0][i] && check[1][i] && check[2][i] && check[3][i] && check[4][i])
		{
			cnt++;
		}
	}

	// 대각선1
	if (check[0][0] && check[1][1] && check[2][2] && check[3][3] && check[4][4])
	{
		cnt++;
	}

	// 대각선2
	if (check[0][4] && check[1][3] && check[2][2] && check[3][1] && check[4][0])
	{
		cnt++;
	}

	return cnt;
}

// Bingo
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> v(5, vector<int>(5));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> v[i][j];
		}
	}

	vector<vector<bool>> check(5, vector<bool>(5));
	for (int i = 0; i < 25; i++)
	{
		int num;
		cin >> num;

		int ans = 0;
		for (int k = 0; k < 5; k++)
		{
			for (int l = 0; l < 5; l++)
			{
				if (v[k][l] == num)
				{
					check[k][l] = true;
				}
			}
		}

		ans += cond(check);
		if (ans >= 3)
		{
			cout << i + 1;
			return 0;
		}
	}

	return 0;
}