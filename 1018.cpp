#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

string WB[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW"
};
string BW[8] = {
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB"
};

int W_cnt(vector<vector<char>> &v, int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (v[x + i][y + j] != WB[i][j])
				cnt++;
		}

	}
	return cnt;
}
int B_cnt(vector<vector<char>>& v, int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (v[x + i][y + j] != BW[i][j])
				cnt++;
		}

	}
	return cnt;
}

// Repainting the chessboard
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			v[i][j] = input[j];
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i + 8 <= n; i++)
	{
		for (int j = 0; j + 8 <= m; j++)
		{
			int cnt;
			cnt = min(W_cnt(v, i, j), B_cnt(v, i, j));
			if (cnt < ans)
			{
				ans = cnt;
			}
		}
	}

	cout << ans;

	return 0;
}