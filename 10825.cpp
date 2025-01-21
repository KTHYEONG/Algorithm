#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool SortCmp(pair<string, vector<int>>& a, pair<string, vector<int>>& b)
{
	// 국어 점수 내림차순
	if (a.second[0] != b.second[0])
	{
		return a.second[0] > b.second[0];
	}
	// 영어 점수 오름차순
	if (a.second[1] != b.second[1])
	{
		return a.second[1] < b.second[1];
	}
	// 수학 점수 내림차순
	if (a.second[2] != b.second[2])
	{
		return a.second[2] > b.second[2];
	}
	// 이름 오름차순
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<string, vector<int>>> v;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;

		int score0, score1, score2;
		cin >> score0 >> score1 >> score2;

		v.push_back(make_pair(name, vector<int>{ score0, score1, score2 }));
	}

	sort(v.begin(), v.end(), SortCmp);

	for (auto element : v)
	{
		cout << element.first << '\n';
	}

	return 0;
}