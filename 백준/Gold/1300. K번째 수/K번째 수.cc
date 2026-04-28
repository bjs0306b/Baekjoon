#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    long long n, k;
    cin >> n >> k;

    long long s = 1, e = n * n, m;

    long long ans;
    while (s <= e)
    {
        m = (s + e) / 2;

        long long cnt = 0; // m 이하 개수 카운트
        for (int i = 1; i <= n; i++)
        {
            cnt += min(n, m / i);
        }

        if (cnt >= k)
        {
            e = m - 1;
            ans = m;
        }
        else
            s = m + 1;
    }

    cout << ans;

    return 0;
}