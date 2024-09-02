#include <string>
#include <vector>

using namespace std;

string solution(int a, int b)
{
    string answer = "";
    int arr[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

    int cnt = b;
    for (int i = 0; i < a - 1; i++)
        cnt += arr[i];

    return day[cnt % 7];
}