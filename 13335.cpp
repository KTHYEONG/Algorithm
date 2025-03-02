#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Truck
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, truckCnt, limitWeight;
	cin >> n >> truckCnt >> limitWeight;

	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int weight;
		cin >> weight;
		v.push_back(weight);
	}

	queue<int> q;
	int time = 0;
	int curWeight = 0;
	for (int i = 0; i < n; i++)
	{
		while (true)
		{
			if (q.size() == truckCnt)
			{
				curWeight -= q.front();
				q.pop();
			}

			if (curWeight + v[i] <= limitWeight)
			{
				break;
			}

			// 다리에 진입한 트럭이 끝에 도달할 때 까지 기다림
			q.push(0);
			time++;
		}

		// 새로운 트럭 다리에 진입
		q.push(v[i]);
		curWeight += v[i];
		time++;
	}

	cout << time + truckCnt;

	return 0;
}