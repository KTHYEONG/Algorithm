#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width, height;
    cin >> width >> height;

    int cutNum;
    cin >> cutNum;

    vector<int> row, col;
    row.push_back(0);
    row.push_back(width);
    col.push_back(0);
    col.push_back(height);

    int cond, num;
    for (int i = 0; i < cutNum; i++)
    {
        cin >> cond >> num;
        if (cond == 0)
        {
            col.push_back(num);
        }
        else
        {
            row.push_back(num);
        }
    }

    sort(row.begin(), row.end());
    sort(col.begin(), col.end());

    int rowMax = -1, colMax = -1;
    for (int i = 0; i < row.size(); i++)
    {
        if (row.size() > i + 1 && row[i + 1] - row[i] > rowMax)
        {
            rowMax = row[i + 1] - row[i];
        }
    }
    for (int i = 0; i < col.size(); i++)
    {
        if (col.size() > i + 1 && col[i + 1] - col[i] > colMax)
        {
            colMax = col[i + 1] - col[i];
        }
    }

    cout << rowMax * colMax;

    return 0;
}