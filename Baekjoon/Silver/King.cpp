#include <iostream>
#include <unordered_map>

using namespace std;

// 방향 배열 정의
int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1}; // R, L, B, T, RT, LT, RB, LB
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

// 범위 체크 함수
bool isValidMove(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main()
{
    string kingPos, stonePos;
    int n;
    cin >> kingPos >> stonePos >> n;

    // 문자열과 방향 인덱스 매핑
    unordered_map<string, int> directionMap = {
        {"R", 0}, {"L", 1}, {"B", 2}, {"T", 3}, {"RT", 4}, {"LT", 5}, {"RB", 6}, {"LB", 7}};

    // 초기 위치 설정
    int kingX = '8' - kingPos[1];
    int kingY = kingPos[0] - 'A';
    int stoneX = '8' - stonePos[1];
    int stoneY = stonePos[0] - 'A';

    for (int i = 0; i < n; i++)
    {
        string move;
        cin >> move;

        int dir = directionMap[move];
        int newKingX = kingX + dx[dir];
        int newKingY = kingY + dy[dir];

        // 킹 이동 범위 체크
        if (!isValidMove(newKingX, newKingY))
            continue;

        // 킹이 돌과 충돌한 경우
        if (newKingX == stoneX && newKingY == stoneY)
        {
            int newStoneX = stoneX + dx[dir];
            int newStoneY = stoneY + dy[dir];

            // 돌 이동 범위 체크
            if (!isValidMove(newStoneX, newStoneY))
                continue;

            stoneX = newStoneX;
            stoneY = newStoneY;
        }

        // 킹 이동
        kingX = newKingX;
        kingY = newKingY;
    }

    // 최종 결과 출력
    cout << (char)(kingY + 'A') << 8 - kingX << endl;
    cout << (char)(stoneY + 'A') << 8 - stoneX << endl;

    return 0;
}
