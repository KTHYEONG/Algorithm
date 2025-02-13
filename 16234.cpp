#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int populations[51][51];
bool visited[51][51];
vector<pair<int, int>> v;	// ���յ��� ��ǥ ���� ����(�α� ���ſ� �̿�)
int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };
int sum = 0;

void Bfs(int x, int y, int n, int l, int r)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty())
	{
		auto qFront = q.front();
		int curX = qFront.first;
		int curY = qFront.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dirX[i];
			int ny = curY + dirY[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			{
				continue;
			}

			int diff = abs(populations[nx][ny] - populations[curX][curY]);
			if (diff < l || diff > r)
			{
				continue;
			}

			if (!visited[nx][ny])
			{
				q.push({ nx, ny });
				visited[nx][ny] = true;
				v.push_back({ nx, ny });
				sum += populations[nx][ny];
			}
		}
	}
}

// Population movement
int main()
{
	int n, l, r;
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> populations[i][j];
		}
	}

	int ans = 0;
	bool isFind = true;
	while (isFind)
	{
		isFind = false;
		// �迭�� ��ü������ ��ȸ�ϸ鼭 ���� ã��(2�� �ݺ��� ��ü �ѹ� ��ȸ -> 1�� �ҿ�)
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					sum = populations[i][j];
					v.clear();
					v.push_back({ i, j });
					Bfs(i, j, n, l, r);
				}

				// ���� �α� �̵�
				if (v.size() >= 2)
				{
					isFind = true;
					for (int k = 0; k < v.size(); k++)
					{
						populations[v[k].first][v[k].second] = sum / v.size();
					}
				}
			}
		}

		if (isFind)
		{
			ans++;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = false;
			}
		}
	}

	cout << ans;

	return 0;
}