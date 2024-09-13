#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> String_Split(string s)
{
    vector<string> v;
    string temp = "";

    for (int i = 0; i < s.length() - 1; i++)
    {
        char cur = s[i];
        char next = s[i + 1];

        if (isalpha(cur) && isalpha(next))
        {
            temp = {cur, next};
            v.push_back(temp);
        }
    }

    return v;
}

int solution(string str1, string str2)
{
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    vector<string> first = String_Split(str1);
    vector<string> second = String_Split(str2);

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    vector<string> Intersection;
    vector<string> Union;

    set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(Intersection));
    set_union(first.begin(), first.end(), second.begin(), second.end(), back_inserter(Union));

    float result = Union.empty() ? 65536 : (float(Intersection.size()) / Union.size()) * 65536;

    return (int)result;
}