#include <iostream>

using namespace std;

// Finding Fractions
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x;
	cin >> x;

	int line = 1;
	while (x - line > 0)
	{
		x -= line;
		line++;
	}

	if (line % 2)
	{
		cout << line + 1 - x << '/' << x;
	}
	else
	{
		cout << x << '/' << line + 1 - x;
	}

	return 0;
}