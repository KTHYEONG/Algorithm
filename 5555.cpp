#include <iostream>
#include <vector>

using namespace std;

// Ring
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string goal;
	cin >> goal;

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		string temp = s + s;
		if (temp.find(goal) != string::npos)
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}