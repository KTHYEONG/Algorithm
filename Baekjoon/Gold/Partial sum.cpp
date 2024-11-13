#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;

    vector<int> answer;

    int element;
    for (int i = 0; i < N; i++)
    {
        cin >> element;
        answer.push_back(element);
    }

    int leftIdx = 0, rightIdx = 0;
    int minLength = 100001;
    int sum = 0;
    while (rightIdx <= N)
    {
        if (sum < S)
        {
            sum += answer[rightIdx++];
        }
        else
        {
            minLength = min(minLength, rightIdx - leftIdx);
            sum -= answer[leftIdx++];
        }
    }

    if (minLength == 100001)
        cout << 0;
    else
        cout << minLength;

    return 0;
}