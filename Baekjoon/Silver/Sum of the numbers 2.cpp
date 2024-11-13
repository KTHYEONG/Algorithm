#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    int leftIdx = 0, rightIdx = 0;
    int sum = 0;
    int cnt = 0;
    while (rightIdx <= N)
    {
        if (sum == M)
        {
            cnt++;
            sum -= numbers[leftIdx++];
        }
        else if (sum < M && rightIdx < N)
            sum += numbers[rightIdx++];
        else
            sum -= numbers[leftIdx++];
    }

    cout << cnt;

    return 0;
}