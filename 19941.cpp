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

			// P ���� K ���� ��ŭ H Ž��
			while (startIdx < endIdx)
			{
				// �ܹ����̰� �ٸ� ����� �������� ���� ���
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