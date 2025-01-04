#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int aNum, bNum;
    cin >> aNum >> bNum;

    vector<int> a;
    for (int i = 0; i < aNum; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }
    vector<int> b;
    for (int i = 0; i < bNum; i++)
    {
        int num;
        cin >> num;
        b.push_back(num);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> c, d;
    set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    set_difference(b.begin(), b.end(), a.begin(), a.end(), back_inserter(d));

    cout << c.size() + d.size();

    return 0;
}