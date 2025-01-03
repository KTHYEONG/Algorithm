#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, string, greater<string>> m;
    for (int i = 0; i < n; i++)
    {
        string name, commute;
        cin >> name >> commute;
        m[name] = commute;
    }

    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second == "enter")
        {
            cout << it->first << '\n';
        }
    }

    return 0;
}