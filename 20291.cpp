#include <iostream>
#include <map>

using namespace std;

// Organising files
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	map<string, int> map;
	for (int i = 0; i < n; i++)
	{
		string fileName;
		cin >> fileName;

		for (int j = 0; j < fileName.length(); j++)
		{
			if (fileName[j] == '.')
			{
				fileName.erase(fileName.begin(), fileName.begin() + j + 1);
				map[fileName]++;
				break;
			}
		}
	}

	for (auto it = map.begin(); it != map.end(); it++)
	{
		cout << (*it).first << ' ' << (*it).second << '\n';
	}

	return 0;
}