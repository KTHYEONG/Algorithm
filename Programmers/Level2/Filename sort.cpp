#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct fileInfo
{
    string head;
    int number;
    int idx;
};

vector<fileInfo> fi;

bool compare(const fileInfo &f1, const fileInfo &f2)
{
    if (f1.head == f2.head)
    {
        if (f1.number == f2.number)
            return f1.idx < f2.idx;
        else
            return f1.number < f2.number;
    }
    else
        return f1.head < f2.head;
}

vector<string> solution(vector<string> files)
{
    vector<string> answer;

    for (int i = 0; i < files.size(); i++)
    {
        // 숫자가 나오는 부분의 위치 기억
        vector<int> numIdx;
        for (int j = 0; j < files[i].size(); j++)
        {
            if (files[i][j] >= '0' && files[i][j] <= '9')
                numIdx.push_back(j);
        }

        // head와 number를 저장
        string head = "";
        for (int j = 0; j < numIdx[0]; j++)
            head += tolower(files[i][j]);
        string number = files[i].substr(numIdx[0], numIdx.size());

        fileInfo f;
        f.head = head;
        f.number = stoi(number);
        f.idx = i;

        fi.push_back(f);
    }

    sort(fi.begin(), fi.end(), compare);
    for (int i = 0; i < fi.size(); i++)
        answer.push_back(files[fi[i].idx]);

    return answer;
}