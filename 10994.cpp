#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Print Star - 19
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	int s = 4 * n - 3;
	vector<vector<char>> v(s, vector<char>(s, ' '));

	int start = 0;
	int end = s - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = start; j <= end; j++)
		{
			v[start][j] = '*';
			v[j][start] = '*';
			v[j][end] = '*';
			v[end][j] = '*';
		}
		start += 2;
		end -= 2;
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << v[i][j];
		}
		cout << '\n';
	}

	return 0;
}