#include <iostream>

using namespace std;

int main()
{
    int s, p;
    cin >> s >> p;

    string DNA;
    cin >> DNA;

    int A, C, G, T;
    cin >> A >> C >> G >> T;

    int ans = 0;
    int aCnt = 0, cCnt = 0, gCnt = 0, tCnt = 0;

    for (int i = 0; i < p; i++)
    {
        switch (DNA[i])
        {
        case 'A':
            aCnt++;
            break;
        case 'C':
            cCnt++;
            break;
        case 'G':
            gCnt++;
            break;
        case 'T':
            tCnt++;
            break;
        }
    }

    if (aCnt >= A && cCnt >= C && gCnt >= G && tCnt >= T)
        ans++;

    // 슬라이딩 윈도우
    for (int i = p; i < s; i++)
    {
        switch (DNA[i - p])
        {
        case 'A':
            aCnt--;
            break;
        case 'C':
            cCnt--;
            break;
        case 'G':
            gCnt--;
            break;
        case 'T':
            tCnt--;
            break;
        }

        switch (DNA[i])
        {
        case 'A':
            aCnt++;
            break;
        case 'C':
            cCnt++;
            break;
        case 'G':
            gCnt++;
            break;
        case 'T':
            tCnt++;
            break;
        }

        if (aCnt >= A && cCnt >= C && gCnt >= G && tCnt >= T)
            ans++;
    }

    cout << ans;

    return 0;
}