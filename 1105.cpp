#include <iostream>

using namespace std;

// Arm
int main()
{
	string l, r;
	cin >> l >> r;

	int ans = 0;
	if (l.length() != r.length())
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < l.length(); i++)
		{
			if (l[i] != r[i])
			{
				break;
			}

			if (l[i] == r[i] && l[i] == '8')
			{
				ans++;
			}
		}

		cout << ans;
	}

	return 0;
}