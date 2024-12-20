#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, score, p;
    cin >> n >> score >> p;

    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    int ans = 0;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    if (n == p)
    {
        if (v[n - 1] >= score)
        {
            ans = -1;
        }
        else
        {
            int cnt = 1;
            for (int i = 0; i < n; i++)
            {
                if (score < v[i])
                    cnt++;
            }
            ans = cnt;
        }
    }
    else
    {
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (score < v[i])
                cnt++;
        }
        ans = cnt;
    }

    cout << ans;

    return 0;
}