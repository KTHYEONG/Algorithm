#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    int left = 1, right = 1;
    int sum = 0;
    while (left <= right && right <= n + 1)
    {
        if (sum > n)
            sum -= left++;
        else if (sum < n)
            sum += right++;
        else
        {
            cnt++;
            sum += right++;
        }
    }

    cout << cnt;

    return 0;
}