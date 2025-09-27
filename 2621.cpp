#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<pair<char, int>, 5> cards;
    for (int i = 0; i < 5; ++i) cin >> cards[i].first >> cards[i].second;

    map<char, int> colorCnt;
    array<int, 10> numCnt{};
    int mxNum = 0;
    for (auto& c : cards)
    {
        colorCnt[c.first]++;
        numCnt[c.second]++;
        mxNum = max(mxNum, c.second);
    }

    // Flush
    bool flush = false;
    for (auto& kv : colorCnt) if (kv.second == 5) flush = true;

    // Straight
    vector<int> nums;
    nums.reserve(5);
    for (int x = 1; x <= 9; ++x) if (numCnt[x]) nums.push_back(x);
    bool straight = (nums.size() == 5 && nums.back() - nums.front() == 4);

    // 4/3/2/1 개수 모으기
    int four = 0, three = 0;
    vector<int> pairs; pairs.reserve(2);
    for (int x = 1; x <= 9; ++x)
    {
        if (numCnt[x] == 4) four = x;
        else if (numCnt[x] == 3) three = x;
        else if (numCnt[x] == 2) pairs.push_back(x);
    }
    sort(pairs.begin(), pairs.end());

    int score = 0;
    if (flush && straight)
    {              
        score = 900 + nums.back();
    }
    else if (four)
    {
        score = 800 + four;
    }
    else if (three && !pairs.empty())
    {
        score = 700 + three * 10 + pairs.back();
    }
    else if (flush)
    {                     
        score = 600 + mxNum;
    }
    else if (straight)
    {                  
        score = 500 + nums.back();
    }
    else if (three)
    {                   
        score = 400 + three;
    }
    else if (pairs.size() == 2)
    {          
        score = 300 + pairs.back() * 10 + pairs.front();
    }
    else if (pairs.size() == 1)
    {          
        score = 200 + pairs[0];
    }
    else
    {                   
        score = 100 + mxNum;
    }

    cout << score << '\n';
    return 0;
}
