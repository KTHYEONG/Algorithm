#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// The alien's guitar playing
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, p;
	cin >> n >> p;

	int ans = 0;
	vector<stack<int>> vStk(8);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		if (vStk[a - 1].empty())
		{
			vStk[a - 1].push(b);
			ans++;
		}
		else if (vStk[a - 1].top() < b)
		{
			vStk[a - 1].push(b);
			ans++;
		}
		else
		{
			while (vStk[a - 1].top() > b)
			{
				vStk[a - 1].pop();
				ans++;
				if (vStk[a - 1].empty())
				{
					vStk[a - 1].push(b);
					ans++;
				}
			}

			if (vStk[a - 1].top() < b)
			{
				vStk[a - 1].push(b);
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}