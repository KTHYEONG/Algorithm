#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    if (cacheSize == 0)
        return cities.size() * 5;

    vector<string> v;
    for (int i = 0; i < cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto it = find(v.begin(), v.end(), cities[i]);

        if (it == v.end())
        {
            if (v.size() == cacheSize)
                v.erase(v.begin());

            answer += 5;
        }
        else
        {
            answer++;
            v.erase(it);
        }

        v.push_back(cities[i]);
    }

    return answer;
}