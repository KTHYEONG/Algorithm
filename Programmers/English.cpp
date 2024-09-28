#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<string, string> vocabulary;

    vocabulary["statement"] = "진술 / 서술 / 성명";

    for (const auto &entry : vocabulary)
    {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
