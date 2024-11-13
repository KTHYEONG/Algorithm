#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int A[4001], B[4001], C[4001], D[4001];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<long long> AB;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            AB.push_back(A[i] + B[j]);
    sort(AB.begin(), AB.end());

    vector<long long> CD;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            CD.push_back(C[i] + D[j]);
    sort(CD.begin(), CD.end());

    long long ans = 0;
    for (int i = 0; i < AB.size(); i++)
    {
        int CD_pre = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        int CD_end = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        ans += CD_end - CD_pre;
    }

    cout << ans;

    return 0;
}