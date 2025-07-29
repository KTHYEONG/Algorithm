#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
string dp[251] = { "1", "1", "3" };

void String_Add(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		string a = dp[i - 1], b = dp[i - 2], c = dp[i - 2];
		string res;
		int sum = 0;
		while (!a.empty() || !b.empty() || !c.empty() || sum)
		{
			if (a != "")
			{
				sum += a.back() - '0';
				a.pop_back();
			}
			if (b != "")
			{
				sum += b.back() - '0';
				b.pop_back();
			}
			if (c != "")
			{
				sum += c.back() - '0';
				c.pop_back();
			}

			res.push_back(sum % 10 + '0');
			sum /= 10;
		}

		reverse(res.begin(), res.end());
		dp[i] = res;
	}
}

// Tiling
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (cin >> n)
	{
		if (n > 2)
		{
			String_Add(2, n);
		}
		cout << dp[n] << '\n';
	}

	return 0;
}