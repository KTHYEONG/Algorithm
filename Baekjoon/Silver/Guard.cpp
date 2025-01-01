#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 도로를 1차원 선분으로 변환
int convertTo1D(int dir, int dis, int row, int col)
{
    if (dir == 1)
        return dis; // 북쪽
    if (dir == 2)
        return col + row + (col - dis); // 남쪽
    if (dir == 3)
        return 2 * (col + row) - dis; // 서쪽
    return col + dis;                 // 동쪽
}

int main()
{
    int col, row;
    cin >> col >> row;

    int n;
    cin >> n;

    vector<int> positions(n);
    for (int i = 0; i < n; i++)
    {
        int dir, dis;
        cin >> dir >> dis;
        positions[i] = convertTo1D(dir, dis, row, col);
    }

    // 동근이 위치
    int dir, dis;
    cin >> dir >> dis;
    int myPos = convertTo1D(dir, dis, row, col);

    int perimeter = 2 * (col + row); // 도로 전체 둘레
    int total = 0;

    for (int pos : positions)
    {
        int clockwise = abs(myPos - pos);             // 시계 방향 거리
        int counterClockwise = perimeter - clockwise; // 반시계 방향 거리
        total += min(clockwise, counterClockwise);
    }

    cout << total << endl;
    return 0;
}
