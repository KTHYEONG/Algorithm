#include <bits/stdc++.h>

using namespace std;

string n;
int idx;
int num = 1;

// Continuing to write
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while (idx != n.length())
	{
		string numStr = to_string(num);

		for (int i = 0; i < numStr.length(); i++)
		{
			if (n[idx] == numStr[i])
			{
				idx++;
				if (idx >= n.length())
				{
					cout << num;
					return 0;
				}
			}
		}

		num++;
	}

	return 0;
}