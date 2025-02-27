#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
 
unordered_map<string, int> um;

bool cmp(const string& a, const string& b)
{
	if (a.length() == b.length() && um[a] == um[b])
	{
		return a < b;
	}
	else if (um[a] == um[b])
	{
		return a.length() > b.length();
	}

	return um[a] > um[b];
}

// Memorising English words is difficult
// Map�� ���� �ܾ��� ����Ƚ�� ����, Vector�� ���� word ���� �� ���ǿ� ���� ���� ����
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<string> words;
	for (int i = 0; i < n; i++)
	{
		string word;
		cin >> word;

		if (word.length() < m)
		{
			continue;
		}

		if (um.find(word) == um.end())
		{
			um[word] = 0;
			words.push_back(word);
		}
		um[word]++;
	}

	sort(words.begin(), words.end(), cmp);

	for (string &element : words)
	{
		cout << element << '\n';
	}

	return 0;
}