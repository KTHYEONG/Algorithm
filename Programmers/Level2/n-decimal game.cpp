#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p)
{
    string answer = "";

    vector<int> v;
    int num = 0;
    p--;

    char digits[] = "0123456789ABCDEF";

    while (v.size() < t * m)
    {
        int cur = num;
        vector<char> temp;

        if (cur == 0)
            temp.push_back('0');
        else
        {
            while (cur > 0)
            {
                temp.insert(temp.begin(), digits[cur % n]);
                cur /= n;
            }
        }

        v.insert(v.end(), temp.begin(), temp.end());
        num++;
    }

    for (int i = 0; i < t; i++)
        answer += v[p + i * m];

    return answer;
}