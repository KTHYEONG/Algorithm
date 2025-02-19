#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

// AC
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<string> ans;
	while (t > 0)
	{
		string order;
		cin >> order;

		int n;
		cin >> n;

		string nums;
		cin >> nums;

		deque<string> dq;
		string temp = "";
		for (char c : nums)
		{
			if (isdigit(c))
			{
				temp += c;
			}
			else if (c == ',' || c == ']')
			{
				if (!temp.empty())
				{
					dq.push_back(temp);
					temp = "";
				}
			}
		}

		bool isReverse = false;
		bool flag = false;
		for (char rd : order)
		{
			if (rd == 'R')
			{
				isReverse = !isReverse;
			}
			else
			{
				if (dq.empty())
				{
					flag = true;
					break;
				}
				else
				{
					if (isReverse)
					{
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
			}
		}

		if (flag)
		{
			ans.push_back("error");
		}
		else
		{
			string result = "[";
			if (isReverse)
			{
				reverse(dq.begin(), dq.end());
			}

			for (int i = 0; i < dq.size(); i++)
			{
				result += dq[i];
				if (i != dq.size() - 1)
				{
					result += ',';
				}
			}
			result += "]";
			ans.push_back(result);
		}

		t--;
	}

	for (string element : ans)
	{
		cout << element << '\n';
	}

	return 0;
}