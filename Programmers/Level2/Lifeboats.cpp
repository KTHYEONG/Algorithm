#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;

    sort(people.begin(), people.end());

    int first = 0, last = people.size() - 1;
    while (first <= last)
    {
        answer++;
        // 2명을 한번에 구출 가능한 경우(불가능한 경우에는 제일 무거운 사람만 보냄)
        if (people[first] + people[last] <= limit)
            first++;
        last--;
    }

    return answer;
}