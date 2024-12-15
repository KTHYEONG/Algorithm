#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int a, p;
    cin >> a >> p;

    vector<int> v(500000, 0);
    int cnt = 1;
    while (v[a] == 0)
    {
        v[a] = cnt++;
        int sum = 0, num = 0;
        while (a)
        {
            num = a % 10;
            sum += pow(num, p);
            a /= 10;
        }
        a = sum;
    }

    cout << v[a] - 1;

    return 0;
}