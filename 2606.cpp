#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101];
bool visited[101];
int cnt = 0;

void Dfs(int x)
{
	visited[x] = true;
	// 감염된 pc와 연결된 pc 탐색
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (!visited[y])
		{
			Dfs(y);
			cnt++;
		}
	}
}

// Virus
// dfs를 통해서 바이러스에 감염된 pc들과 연결된 pc를 찾아내는 방법
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int pcNum;
	cin >> pcNum;

	int pcPairNum;
	cin >> pcPairNum;

	for (int i = 0; i < pcPairNum; i++)
	{
		int pc0, pc1;
		cin >> pc0 >> pc1;
		v[pc0].push_back(pc1);
		v[pc1].push_back(pc0);
	}

	Dfs(1);

	cout << cnt;

	return 0;
}