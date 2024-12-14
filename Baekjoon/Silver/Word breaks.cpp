#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string ans = "{";
    for (int i = 0; i < s.length() - 2; i++)
    {
        for (int j = i + 1; j < s.length() - 1; j++)
        {
            string v;

            for (int k = i; k >= 0; k--)
            {
                v += s[k];
            }

            for (int k = j; k > i; k--)
            {
                v += s[k];
            }

            for (int k = s.length() - 1; k > j; k--)
            {
                v += s[k];
            }

            if (ans > v)
                ans = v;
        }
    }

    cout << ans;

    return 0;
}