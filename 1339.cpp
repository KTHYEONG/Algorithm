#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Word Math
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(26, 0);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		// 자리수 계산
		int value = 1;
		for (int j = str.length() - 1; j >= 0; j--)
		{
			v[str[j] - 'A'] += value;
			value *= 10;
		}
	}

	sort(v.begin(), v.end(), greater<int>());

	int num = 9;
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		if (v[i] == 0)
		{
			break;
		}

		ans += v[i] * num;
		num--;
	}

	cout << ans;

	return 0;
}