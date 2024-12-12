#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getCharFreq(string &s)
{
    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'A']++;
    }

    return freq;
}

bool isSimilarWord(string &goal, string &check)
{
    int lenDiff = abs((int)goal.length() - (int)check.length());

    // 길이가 2 이상 차이가 나면 비슷한 단어 불가능
    if (lenDiff > 1)
        return false;

    auto freqGoal = getCharFreq(goal);
    auto freqCheck = getCharFreq(check);

    int diffCnt = 0;
    for (int i = 0; i < 26; i++)
    {
        diffCnt += abs(freqGoal[i] - freqCheck[i]);
    }

    // 길이가 같은 경우 -> 1개씩만 다른 경우 허용됨
    if (lenDiff == 0)
        return diffCnt <= 2;

    // 길이가 다른 경우 -> 삭제 or 추가로 1개를 맞출 수 있어야 함
    return diffCnt <= 1;
}

int main()
{
    int n;
    cin >> n;

    string goal;
    cin >> goal;

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        string check;
        cin >> check;

        if (isSimilarWord(goal, check))
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}