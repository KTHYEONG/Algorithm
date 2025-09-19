#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<int> dir(6);
vector<int> len(6);

// Korean melon field
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	
	for (int i = 0; i < 6; i++)
	{
		cin >> dir[i] >> len[i];
	}

	int maxW = 0, widx = -1;
	int maxH = 0, hidx = -1;

	for (int i = 0; i < 6; i++)
	{
		// 가로
		if (dir[i] == 1 || dir[i] == 2)
		{
			if (len[i] > maxW)
			{
				maxW = len[i];
				widx = i;
			}
		}
		// 세로
		else 
		{
			if (len[i] > maxH)
			{
				maxH = len[i];
				hidx = i;
			}
		}
	}

	int smallW = len[(widx + 3) % 6];
	int smallH = len[(hidx + 3) % 6];

	long long bigArea = maxW * maxH;
	long long smallArea = smallW * smallH;
	long long ans = (bigArea - smallArea) * k;

	cout << ans;

	return 0;
}