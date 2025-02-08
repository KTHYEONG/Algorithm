#include <iostream>
#include <algorithm>

using namespace std;

char board[21][21];
bool alphabetCheck[26] = { false };
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };
int ans = 1;

void Dfs(int x, int y, int r, int c, int cnt)
{
	// �湮�� ���ĺ� üũ
	alphabetCheck[board[x][y] - 'A'] = true;

	// �ִ� �̵� ĭ �� ����
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++)
	{
		// ��� ���� 4����(��,��,��,��) Ž��
		int nx = x + dirX[i];
		int ny = y + dirY[i];

		// �湮 ������ ������� üũ(���� �� ���ĺ�)
		if (nx >= 0 && ny >= 0 && nx < r && ny < c && !alphabetCheck[board[nx][ny] - 'A'])
		{
			Dfs(nx, ny, r, c, cnt + 1);
		}
	}

	// ��Ʈ��ŷ -> ���� ��忡�� ������ Ž���� ��� ���� �� �ǵ��� �� �� �ٽ� �湮 ������ ��尡
	// �ǵ��� ����
	alphabetCheck[board[x][y] - 'A'] = false;
}

// Alphabet
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}

	Dfs(0, 0, r, c, 1);

	cout << ans;

	return 0;
}