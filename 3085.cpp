#include <iostream>
#include <vector>

using namespace std;

void Swap(vector<vector<char>>& v, int x, int y)
{
	char temp = v[x][y];
	v[x][y] = v[x][y + 1];
	v[x][y + 1] = temp;
}

int Check(vector<vector<char>>& v, int n)
{
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 1; j < n; j++)
		{
			if (v[i][j] == v[i][j - 1])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}
			ans = max(ans, cnt);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 1; j < n; j++)
		{
			if (v[j][i] == v[j - 1][i])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}
			ans = max(ans, cnt);
		}
	}

	return ans;
}

// Candy Game
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<char>> v(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			v[i][j] = input[j];
		}
	}

	int maxCnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)
			{
				swap(v[i][j], v[i][j + 1]);
				maxCnt = max(maxCnt, Check(v, n));
				swap(v[i][j], v[i][j + 1]);
			}

			if (i + 1 < n)
			{
				swap(v[i][j], v[i + 1][j]);
				maxCnt = max(maxCnt, Check(v, n));
				swap(v[i][j], v[i + 1][j]);
			}
		}
	}

	cout << maxCnt;

	return 0;
}