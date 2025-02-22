#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// String Explosion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string word, boom;
	cin >> word >> boom;

	stack<char> stk;

	for (int i = 0; i < word.length(); i++)
	{
		stk.push(word[i]);

		if (word[i] == boom[boom.length() - 1] && stk.size() >= boom.length())
		{
			string temp;
			for (int j = 0; j < boom.length(); j++)
			{
				temp += stk.top();
				stk.pop();
			}

			reverse(temp.begin(), temp.end());

			if (temp.compare(boom) != 0)
			{
				for (int i = 0; i < temp.length(); i++)
				{
					stk.push(temp[i]);
				}
			}
		}
	}

	string ans = "";
	while (!stk.empty())
	{
		ans += stk.top();
		stk.pop();
	}

	reverse(ans.begin(), ans.end());

	if (ans == "")
	{
		cout << "FRULA";
	}
	else
	{
		cout << ans;
	}

	return 0;
}