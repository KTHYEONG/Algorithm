#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Integer triangle
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++)
    {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }

    vector<vector<int>> dp = triangle;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';

	return 0;
}