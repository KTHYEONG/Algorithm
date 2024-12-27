#include <iostream>
#include <vector>

using namespace std;

void Calculate(vector<vector<int>> &v, int n)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                int sum = v[n][i] + v[n][j] + v[n][k];
                int result = sum % 10;
                v[n][5] = max(v[n][5], result);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(6, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> v[i][j];
        }

        Calculate(v, i);
    }

    int maxNum = v[0][5];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i][5] >= maxNum)
        {
            maxNum = v[i][5];
            ans = i;
        }
    }

    cout << ans + 1;

    return 0;
}