#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<long long> v(101, 0);
    v[1] = v[2] = v[3] = 1;

    for (int i = 4; i < 101; i++)
        v[i] = v[i - 3] + v[i - 2];

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << v[n] << endl;
    }

    return 0;
}