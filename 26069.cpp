#include <bits/stdc++.h>

using namespace std;

int n;
unordered_map<string, bool> um;

// The affectionate Chongchong
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	set<string> cnt;
	cnt.insert("ChongChong");

	for (int i = 0; i < n; i++)
	{
		string name1, name2;
		cin >> name1 >> name2;

		for (string dancing : cnt)
		{
			if (dancing == name1) {
				cnt.insert(name2);
			}

			if (dancing == name2) {
				cnt.insert(name1);
			}
		}
	}

	cout << cnt.size();

	return 0;
}