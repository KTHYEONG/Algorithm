#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        int num = arr1[i] | arr2[i];
        bitset<16> pushNum(num);

        string temp = "";
        for (int j = n - 1; j >= 0; j--)
            temp += pushNum[j] ? "#" : " ";

        answer.push_back(temp);
    }

    return answer;
}