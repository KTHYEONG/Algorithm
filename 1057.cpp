#include <iostream>
#include <vector>

using namespace std;

// Tournament
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, num1, num2;
	cin >> n >> num1 >> num2;

	int cnt = 0;
	while (num1 != num2)
	{
		num1 = (num1 + 1) / 2;
		num2 = (num2 + 1) / 2;
		cnt++;
	}

	cout << cnt;
	
	return 0;
}