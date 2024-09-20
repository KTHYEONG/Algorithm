#include <string>
#include <map>

using namespace std;

int solution(string dirs)
{
    int answer = 0;

    map<pair<pair<int, int>, pair<int, int>>, bool> table;
    int x = 0, y = 0, nx = 0, ny = 0;
    for (char d : dirs)
    {
        if (d == 'U' && ny + 1 <= 5)
            ny++;
        else if (d == 'D' && ny - 1 >= -5)
            ny--;
        else if (d == 'R' && nx + 1 <= 5)
            nx++;
        else if (d == 'L' && nx - 1 >= -5)
            nx--;
        else
            continue;

        // 처음가는 길인지 체크
        if (table.find(make_pair(make_pair(x, y), make_pair(nx, ny))) == table.end() && table.find(make_pair(make_pair(nx, ny), make_pair(x, y))) == table.end())
        {
            table.insert({{{x, y}, {nx, ny}}, true});
            answer++;
        }

        x = nx;
        y = ny;
    }

    return answer;
}