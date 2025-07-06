#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Number game
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	string numbers[11] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<pair<string, int>> ans;

	string temp;
	for (int i = m; i <= n; i++)
	{
		if (i >= 10)
		{
			temp = numbers[i / 10] + " " + numbers[i % 10];
		}
		else
		{
			temp = numbers[i % 10];
		}

		ans.push_back({ temp, i });
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].second << ' ';
		if (i % 10 == 9)
		{
			cout << '\n';
		}
	}

	return 0;
}