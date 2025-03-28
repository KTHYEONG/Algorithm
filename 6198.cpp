#include <iostream>
#include <stack>

using namespace std;

// Creating a rooftop garden
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long ans = 0;
	stack<int> stk;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (!stk.empty() && stk.top() <= num)
		{
			stk.pop();
		}

		ans += stk.size();
		stk.push(num);
	}

	cout << ans;

	return 0;
}