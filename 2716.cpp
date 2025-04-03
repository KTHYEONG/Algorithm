#include <iostream>
#include <string>

using namespace std;

// Hanging Monkeys
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string input;
		getline(cin, input);

		int ans = 0;
		int depth = 0;
		for (int j = 0; j < input.length(); j++)
		{
			depth += (input[j] == '[' ? 1 : -1);
			ans = max(ans, depth);
		}

		cout << (1 << ans) << '\n';
	}

	return 0;
}