#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int table[101][101];

// Floyd
// 플로이드-워셜 알고리즘 사용 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cities;
	cin >> cities;

	int busCnt;
	cin >> busCnt;

	// 초기 배열 설정
	for (int i = 1; i <= cities; i++)
	{
		for (int j = 1; j <= cities; j++)
		{
			if (i == j)
			{
				table[i][j] = 0;
			}
			else
			{
				table[i][j] = INT_MAX;
			}
		}
	}

	for (int i = 0; i < busCnt; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		table[start][end] = min(table[start][end], cost);
	}

	// 코스트 계산
	for (int k = 1; k <= cities; k++)
	{
		for (int i = 1; i <= cities; i++)
		{
			for (int j = 1; j <= cities; j++)
			{
				if (table[i][k] != INT_MAX && table[k][j] != INT_MAX)
				{
					table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
				}
			}
		}
	}

	// 출력
	for (int i = 1; i <= cities; i++)
	{
		for (int j = 1; j <= cities; j++)
		{
			if (table[i][j] == INT_MAX)
			{
				cout << 0 << ' ';
				continue;
			}
			cout << table[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}