#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// DNA
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	string ansStr = "";
	int ansCnt = 0;
	for (int i = 0; i < m; i++)
	{
		int maxCnt = 0;
		char maxChar = 'a';
		map<char, int> m;
		for (int j = 0; j < n; j++)
		{
			m[v[j][i]]++;
		}

		for (auto element : m)
		{
			if (element.second > maxCnt)
			{
				maxCnt = element.second;
				maxChar = element.first;
			}
		}

		ansStr += maxChar;
		ansCnt += n - maxCnt;
	}

	cout << ansStr << '\n' << ansCnt;

	return 0;
}