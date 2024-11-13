#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> check(d + 1, 0); // 각 초밥의 중복 체크
    int currentUnique = 0;       // 현재 고유한 초밥의 개수
    int ans = 0;

    // 초기 설정
    for (int i = 0; i < k; i++)
    {
        if (check[v[i]] == 0)
            currentUnique++; // 새로운 초밥 발견
        check[v[i]]++;       // 초밥 개수 증가
    }

    // 쿠폰 초밥이 없으면 추가
    ans = currentUnique + (check[c] == 0 ? 1 : 0);

    // 전체 확인
    for (int i = 1; i < n; i++)
    {
        // 이전 초밥 제거
        int removeSushi = v[i - 1];
        check[removeSushi]--;
        if (check[removeSushi] == 0)
            currentUnique--; // 더 이상 없는 초밥

        // 새로 추가되는 초밥
        int addSushi = v[(i + k - 1) % n];
        if (check[addSushi] == 0)
            currentUnique++; // 새로운 초밥 발견
        check[addSushi]++;

        // 현재 고유 초밥 개수 + 쿠폰 초밥이 있는지 확인
        ans = max(ans, currentUnique + (check[c] == 0 ? 1 : 0));
    }

    cout << ans << endl;

    return 0;
}
