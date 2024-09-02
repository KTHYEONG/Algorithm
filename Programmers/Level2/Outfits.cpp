#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> table;
    for (auto c : clothes)
        table[c[1]]++;

    // 가능한 경우의 수
    for (auto c : table)
        answer *= ++c.second;

    // 아무것도 안 입는 경우 1개 빼기
    return answer - 1;
}