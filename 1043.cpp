#include <iostream>

using namespace std;

int parent[51];

int Find(int a)
{
	if (a != parent[a])
	{
		return parent[a] = Find(parent[a]);
	}
	else
	{
		return parent[a];
	}
}

void Union(int x, int y)
{
	int nx = Find(parent[x]);
	int ny = Find(parent[y]);
	if (nx != ny)
	{
		if (nx < ny)
		{
			parent[ny] = parent[nx];
		}
		else
		{
			parent[nx] = parent[ny];
		}
	}
}

// Lie
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int knowTruth;
	cin >> knowTruth;

	for (int i = 0; i < 51; i++)
	{
		parent[i] = i;
	}

	// 진실을 아는 사람은 0 집합으로 설정
	for (int i = 0; i < knowTruth; i++)
	{
		int person;
		cin >> person;
		parent[person] = 0;
	}

	int party[51][51];
	int partyNum[51];
	for (int i = 0; i < m; i++)
	{
		int people;
		cin >> people;
		partyNum[i] = people;

		for (int j = 0; j < people; j++)
		{
			int person;
			cin >> person;
			party[i][j] = person;
			
			if (j > 0)
			{
				Union(party[i][j - 1], person);
			}
		}
	}

	int ans = m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < partyNum[i]; j++)
		{
			if (Find(parent[party[i][j]]) == 0)
			{
				ans--;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}