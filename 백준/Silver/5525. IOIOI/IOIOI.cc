#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    int cnt = 0, ans = 0;
    for (int i = 1; i < k - 1; i++)
    {
        if (s[i] == 'O')
        {
            if (s[i - 1] == 'I' && s[i + 1] == 'I')
            {
                cnt++;
                i++;
            }
            else
            {
                if (cnt >= n)
                    ans += cnt - n + 1;
                cnt = 0;
            }
        }
        else
        {
            if (cnt >= n)
                ans += cnt - n + 1;
            cnt = 0;
        }
    }
    if (cnt >= n) ans += cnt - n + 1;
    cout << ans;

    return 0;
}