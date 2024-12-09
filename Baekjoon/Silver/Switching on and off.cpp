#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int switchNum;
    cin >> switchNum;

    vector<int> switchState(switchNum, 0);
    for (int i = 0; i < switchNum; i++)
    {
        cin >> switchState[i];
    }

    int studentNum = 0;
    cin >> studentNum;

    int sex, number;
    for (int i = 0; i < studentNum; i++)
    {
        cin >> sex >> number;

        // 남자
        if (sex == 1)
        {
            for (int j = number - 1; j < switchState.size(); j += number)
            {
                switchState[j] = switchState[j] == 1 ? 0 : 1;
            }
        }
        // 여자
        else
        {
            int leftIdx = number - 2;
            int rightIdx = number;

            switchState[number - 1] = switchState[number - 1] == 1 ? 0 : 1;

            while (leftIdx >= 0 && rightIdx < switchNum && switchState[leftIdx] == switchState[rightIdx])
            {
                switchState[leftIdx] = switchState[leftIdx] == 1 ? 0 : 1;
                switchState[rightIdx] = switchState[rightIdx] == 1 ? 0 : 1;
                leftIdx--;
                rightIdx++;
            }
        }
    }

    for (int i = 0; i < switchNum; i++)
    {
        cout << switchState[i] << " ";
        if ((i + 1) % 20 == 0)
            cout << endl;
    }

    return 0;
}