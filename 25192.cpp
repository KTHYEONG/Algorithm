#include <iostream>
#include <unordered_set>

using namespace std;

// Personable Gomgom
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	unordered_set<string> us;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		if (input == "ENTER")
		{
			us.clear();
			continue;
		}

		if (us.find(input) == us.end())
		{
			us.insert(input);
			ans++;
		}
	}

	cout << ans;
}