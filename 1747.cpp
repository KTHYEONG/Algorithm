#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

bool isPalindrome(int n)
{
	string s = to_string(n);
	int len = s.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - i - 1]) return false;
	}
	return true;
}

// Prime & Palindrome
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	while (true)
	{
		if (isPrime(n) && isPalindrome(n))
		{
			cout << n;
			break;
		}
		n++;
	}

	return 0;
}