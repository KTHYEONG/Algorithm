#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> countNum(10);

bool Check_Cnt() {
	int cnt = 0;
	for (int i = 1; i < 10; i++)
	{
		if (countNum[i] > 0) {
			cnt++;
		}
	}

	if (cnt > 2) { return true; }

	return false;
}

// Fruit Tanghulu
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	v.resize(n);

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	
	int ans = 0;
	int left = 0, right = 0;
	while (left < n) {
		while (right < n) {
			countNum[v[right++]]++;
			if (Check_Cnt()) {
				right--;
				countNum[v[right]]--;
				break;
			}
		}

		ans = max(ans, right - left);
		countNum[v[left++]]--;
	}

	cout << ans;

	return 0;
}