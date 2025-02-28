#include <iostream>
#include <unordered_set>

using namespace std;

// Number of different substring
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	unordered_set<string> us;
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i; j < s.length(); j++)
		{
			temp += s[j];
			us.insert(temp);
		}
		temp = "";
	}

	cout << us.size();

	return 0;
}