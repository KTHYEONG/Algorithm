#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> order;

// Game of Death
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	order.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> order[i];
	}

	vector<bool> visited(n);
	int temp = order[0];
	int cnt = 0;
	while (!visited[temp])
	{
		visited[temp] = true;
		cnt++;

		if (temp == k)
		{
			cout << cnt;
			return 0;
		}

		temp = order[temp];
	}

	cout << -1;
		 
	return 0;
}