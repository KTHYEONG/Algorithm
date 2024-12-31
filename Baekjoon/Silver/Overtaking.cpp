#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> v;
    for (int i = 0; i < n; i++)
    {
        string carNum;
        cin >> carNum;
        v[carNum] = i;
    }

    vector<int> f(n, 0);
    for (int i = 0; i < n; i++)
    {
        string carNum;
        cin >> carNum;
        f[i] = v[carNum];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (f[i] > f[j])
            {
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}