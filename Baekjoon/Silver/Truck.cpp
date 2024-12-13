#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, w, l;
    cin >> n >> w >> l;

    vector<int> trucks(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> trucks[i];
    }

    int ans = 0;
    int sum = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            if (q.size() == w)
            {
                sum -= q.front();
                q.pop();
            }

            if (trucks[i] + sum <= l)
                break;

            q.push(0);
            ans++;
        }
        q.push(trucks[i]);
        sum += trucks[i];
        ans++;
    }

    cout << ans + w;

    return 0;
}