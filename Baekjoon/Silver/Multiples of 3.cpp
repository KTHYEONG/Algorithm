#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string ans = "YES";

    if (s.length() == 1)
    {
        cout << "0\n"
             << ((s[0] - '0') % 3 == 0 ? "YES" : "NO");
        return 0;
    }

    int cnt = 0;
    while (true)
    {
        cnt++;

        int num = 0;
        for (char c : s)
        {
            num += c - '0';
        }

        if (num >= 10)
        {
            s = to_string(num);
        }
        else
        {
            if (num % 3 != 0)
            {
                ans = "NO";
            }
            break;
        }
    }

    cout << cnt << endl
         << ans;

    return 0;
}