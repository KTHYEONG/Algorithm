#include <iostream>

using namespace std;

// String
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	cin >> a >> b;

	int minCnt = 51;
	for (int i = 0; i <= b.length() - a.length(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] != b[i + j])
			{
				cnt++;
			}
		}
		minCnt = min(minCnt, cnt);
	}
	
	cout << minCnt;

	return 0;
}