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
	// 방문한 알파벳 체크
	alphabetCheck[board[x][y] - 'A'] = true;

	// 최대 이동 칸 수 갱신
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++)
	{
		// 노드 기준 4방향(상,하,좌,우) 탐색
		int nx = x + dirX[i];
		int ny = y + dirY[i];

		// 방문 가능한 노드인지 체크(범위 및 알파벳)
		if (nx >= 0 && ny >= 0 && nx < r && ny < c && !alphabetCheck[board[nx][ny] - 'A'])
		{
			Dfs(nx, ny, r, c, cnt + 1);
		}
	}

	// 백트래킹 -> 현재 노드에서 가능한 탐색이 모두 끝난 후 되돌아 갈 때 다시 방문 가능한 노드가
	// 되도록 설정
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