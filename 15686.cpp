#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<pair<int, int>> houses, chickens;

int city_dist(const vector<int>& pick)
{
	int total = 0;
	for (auto item1 : houses)
	{
		int best = INT_MAX;
		for (int idx : pick)
		{
			auto item2 = chickens[idx];
			best = min(best, abs(item1.first - item2.first) + abs(item1.second - item2.second));
		}
		total += best;
	}
	return total;
}

// Chicken delivery
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) houses.push_back({ i, j });
			else if (a[i][j] == 2) chickens.push_back({ i, j });
		}
	}
	
	int C = (int)chickens.size();
	vector<int> idx(C);
	fill(idx.begin(), idx.begin() + m, 1);

	int ans = INT_MAX;
	do
	{
		vector<int> pick;
		pick.reserve(m);
		for (int i = 0; i < C; i++)
			if (idx[i]) pick.push_back(i);
		ans = min(ans, city_dist(pick));
	} while (prev_permutation(idx.begin(), idx.end()));

	cout << ans;

	return 0;
}