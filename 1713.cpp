#include <bits/stdc++.h>

using namespace std;

int n, k;

struct Frame
{
	int stu;
	int cnt;
	int idx;
};

// Recommend a Candidate
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	vector<Frame> v;
	v.reserve(n);

	for (int i = 0; i < k; i++)
	{
		int stu;
		cin >> stu;

		auto it = find_if(v.begin(), v.end(),
						  [stu](const Frame& f) { return f.stu == stu; });
		// 후보가 이미 있는 경우 -> cnt 증가
		if (it != v.end())
		{
			it->cnt++;
			continue;
		}

		// 후보가 없지만 공간이 있는 경우 -> 등록
		if (v.size() < n)
		{
			v.push_back({ stu, 1, i });
			continue;
		}

		// 공간이 부족한 경우 -> 후보 등록을 위해 기존 후보 제거
		int temp = 0;
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i].cnt < v[temp].cnt)
			{
				temp = i;
			}
			else if (v[i].cnt == v[temp].cnt && v[i].idx < v[temp].idx)
			{
				temp = i;
			}
		}
		v[temp] = { stu, 1, i };
	}

	vector<int> ans;
	ans.reserve(v.size());

	for (auto& f : v) ans.push_back(f.stu);
	
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}