#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool SortCmp(const string& a, const string& b)
{
	// 문자열 길이로 비교
	if (a.length() != b.length())
	{
		return a.length() < b.length();
	}

	// 자리수의 합으로 비교
	int sumA = 0;
	for (char c : a)
	{
		if (c >= '0' && c <= '9')
		{
			sumA += c - '0';
		}
	}
	int sumB = 0;
	for (char c : b)
	{
		if (c >= '0' && c <= '9')
		{
			sumB += c - '0';
		}
	}
	if (sumA != sumB)
	{
		return sumA < sumB;
	}

	// 사전순 비교
	return a < b;
}

// Serial number
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> gitars(n);
	for (int i = 0; i < n; i++)
	{
		cin >> gitars[i];
	}

	sort(gitars.begin(), gitars.end(), SortCmp);

	for (string s: gitars)
	{
		cout << s << '\n';
	}

	return 0;
}