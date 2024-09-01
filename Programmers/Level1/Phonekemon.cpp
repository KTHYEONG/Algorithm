#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    int numsSize = nums.size();
    set<int> table;
    for (int element : nums)
        table.insert(element);

    if (table.size() >= numsSize / 2)
        answer = numsSize / 2;
    else
        answer = table.size();

    return answer;
}