#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string ans = "Valid";
    string input[36];

    vector<vector<bool>> v(6, vector<bool>(6, false));
    for (int i = 0; i < 36; i++)
    {
        string pos;
        cin >> pos;
        input[i] = pos;

        int col = pos[0] - 'A';
        int row = pos[1] - '1';

        if (v[row][col] == false)
        {
            v[row][col] = true;
        }
        else
        {
            ans = "Invalid";
            cout << ans;
            return 0;
        }
    }

    // 나이트 이동 검증
    for (int i = 1; i < 36; i++)
    {
        int prevCol = input[i - 1][0] - 'A';
        int prevRow = input[i - 1][1] - '0' - 1;
        int currCol = input[i][0] - 'A';
        int currRow = input[i][1] - '0' - 1;

        if (!((abs(currRow - prevRow) == 2 && abs(currCol - prevCol) == 1) ||
              (abs(currRow - prevRow) == 1 && abs(currCol - prevCol) == 2)))
        {
            ans = "Invalid";
            cout << ans;
            return 0;
        }
    }

    // 마지막 -> 처음 검증
    int firstCol = input[0][0] - 'A';
    int firstRow = input[0][1] - '0' - 1;
    int lastCol = input[35][0] - 'A';
    int lastRow = input[35][1] - '0' - 1;

    if (!((abs(lastRow - firstRow) == 2 && abs(lastCol - firstCol) == 1) ||
          (abs(lastRow - firstRow) == 1 && abs(lastCol - firstCol) == 2)))
    {
        ans = "Invalid";
    }

    cout << ans;

    return 0;
}