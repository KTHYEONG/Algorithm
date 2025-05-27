#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> v(51, vector<vector<int>>(51, vector<int>(51)));

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}

	if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}

	if (v[a][b][c] != 0)
	{
		return v[a][b][c];
	}

	if (a < b && b < c)
	{
		v[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		v[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}

	return v[a][b][c];
}

// Run exciting functions
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}

	return 0;
}