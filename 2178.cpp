#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int maze[101][101] = { 0, };
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void Bfs(int x, int y, int n, int m)
{
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty())
	{
		auto popNum = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = popNum.first + dirX[i];
			int ny = popNum.second + dirY[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			{
				continue;
			}

			if (maze[nx][ny] == 1)
			{
				q.push({ nx, ny });
				maze[nx][ny] = maze[popNum.first][popNum.second] + 1;
			}
		}
	}
}

// Navigating the maze
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		for (int j = 0; j < input.length(); j++)
		{
			maze[i][j] = input[j] - '0';
		}
	}

	Bfs(0, 0, n, m);

	cout << maze[n - 1][m - 1];

	return 0;
}