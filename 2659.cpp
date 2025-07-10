#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int GetClockNum(vector<int> &v)
{
	int num = 9999;
	for (int i = 0; i < 4; i++)
	{
		int n = v[i % 4] * 1000 + v[(i + 1) % 4] * 100 + v[(i + 2) % 4] * 10 + v[(i + 3) % 4];
		num = min(num, n);
	}

	return num;
}

// Crossword puzzle problem
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> v(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> v[i];
	}

	int target = GetClockNum(v);

	set<int> s;
	for (int i = 1111; i <= 9999; i++)
	{
		vector<int> temp = {
			(i / 1000) % 10,
			(i / 100) % 10,
			(i / 10) % 10,
			i % 10
		};

		if (find(temp.begin(), temp.end(), 0) != temp.end())
		{
			continue;
		}

		s.insert(GetClockNum(temp));
	}

	int cnt = 1;
	for (int val : s)
	{
		if (val == target)
		{
			break;
		}
		cnt++;
	}

	cout << cnt;

	return 0;
}