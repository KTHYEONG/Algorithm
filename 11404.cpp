#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int table[101][101];

// Floyd
// �÷��̵�-���� �˰��� ��� 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cities;
	cin >> cities;

	int busCnt;
	cin >> busCnt;

	// �ʱ� �迭 ����
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

	// �ڽ�Ʈ ���
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

	// ���
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