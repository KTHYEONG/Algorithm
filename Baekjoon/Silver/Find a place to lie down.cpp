#include <iostream>
#include <vector>

using namespace std;

int countSpaces(const vector<vector<char>> &v, int n, bool isHorizontal)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // 가로 or 세로 선택
            char current = isHorizontal ? v[i][j] : v[j][i];
            if (current == '.')
            {
                cnt++;
            }
            else
            {
                if (cnt >= 2)
                    count++;
                cnt = 0;
            }
        }

        // 구간이 배열 끝까지 이어지는 경우 처리
        if (cnt >= 2)
            count++;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> v(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }

    int horizontal = countSpaces(v, n, true); // 가로 탐색
    int vertical = countSpaces(v, n, false);  // 세로 탐색

    cout << horizontal << " " << vertical << endl;

    return 0;
}
