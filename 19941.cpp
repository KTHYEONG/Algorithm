#include <iostream>

using namespace std;

bool visited[20001];

// Distributing Burgers
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	string table;
	cin >> table;

	for (int i = 0; i < table.length(); i++)
	{
		if (table[i] == 'H')
		{
			visited[i] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i < table.length(); i++)
	{
		if (table[i] == 'P')
		{
			int startIdx = max(0, i - k);
			int endIdx = min(n, i + k + 1);

			// P 기준 K 범위 만큼 H 탐색
			while (startIdx < endIdx)
			{
				// 햄버거이고 다른 사람이 선택한적 없는 경우
				if (table[startIdx] == 'H' && visited[startIdx])
				{
					visited[startIdx] = false;
					ans++;
					break;
				}

				startIdx++;
			}
		}
	}

	cout << ans;

	return 0;
}