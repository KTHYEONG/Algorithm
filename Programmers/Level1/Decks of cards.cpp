#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    string answer = "Yes";

    int idx1 = 0, idx2 = 0, idx3 = 0;
    while (idx3 < goal.size())
    {
        bool flag = false;
        if (cards1[idx1] == goal[idx3])
        {
            idx1++;
            idx3++;
            flag = true;
        }

        if (cards2[idx2] == goal[idx3])
        {
            idx2++;
            idx3++;
            flag = true;
        }

        if (flag == false)
        {
            answer = "No";
            break;
        }
    }

    return answer;
}