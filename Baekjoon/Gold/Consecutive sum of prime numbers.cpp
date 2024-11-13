#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<bool> prime(N + 1, true);
    vector<int> v;

    if (N == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 2; i * i <= N; i++)
    {
        for (int j = i * 2; j <= N; j += i)
            prime[j] = false;
    }

    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
            v.push_back(i);
    }

    int cnt = 0;
    int leftIdx = 0, rightIdx = 0;
    int sum = 0;
    while (1)
    {
        if (sum > N)
            sum -= v[leftIdx++];
        else if (rightIdx == v.size())
            break;
        else
            sum += v[rightIdx++];

        if (sum == N)
            cnt++;
    }

    cout << cnt;

    return 0;
}