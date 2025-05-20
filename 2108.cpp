#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> freq(8001, 0);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        freq[v[i] + 4000]++;
    }

    sort(v.begin(), v.end());

    // 1. ������
    cout << (int)round((double)sum / n) << '\n';

    // 2. �߾Ӱ�
    cout << v[n / 2] << '\n';

    // 3. �ֺ�
    int modeMax = *max_element(freq.begin(), freq.end());
    vector<int> modes;

    for (int i = 0; i < 8001; i++)
    {
        if (freq[i] == modeMax)
            modes.push_back(i - 4000);
    }

    // �� ��°�� ���� �� ���
    if (modes.size() >= 2)
        cout << modes[1] << '\n';
    else
        cout << modes[0] << '\n';

    // 4. ����
    cout << v[n - 1] - v[0] << '\n';

    return 0;
}
