#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int total = 0;
    for (int i = 0; i < K; i++)
        total += v[i];

    int leftIdx = 0, rightIdx = K - 1;
    int ans = INT_MIN;
    for (int i = 0; i <= N - K; i++)
    {
        ans = max(ans, total);
        if (rightIdx == N - 1)
            break;
        else
        {
            total -= v[leftIdx++];
            total += v[++rightIdx];
        }
    }

    cout << ans;

    return 0;
}