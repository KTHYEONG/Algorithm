#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    int arr[10000001] = {0};
    for (int size : tangerine)
        arr[size]++;
    sort(arr, arr + 10000001, greater<int>());

    int idx = 0;
    while (true)
    {
        k -= arr[idx++];
        answer++;
        if (k <= 0)
            break;
    }

    return answer;
}