#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> s1, s2;
vector<int> dif;
void input()
{
    cin >> n;
    s1.resize(n);
    s2.resize(n);
    dif.resize(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '0')
            s1[i] = false;
        else
            s1[i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '0')
            s2[i] = false;
        else
            s2[i] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            dif[i] = 0;
        else
            dif[i] = 1;
    }
}

void solve()
{
    int ans = INT32_MAX;
    // 맨 처음꺼 그냥 냅둠.
    vector<int> temp1(n, 0);
    int cnt1 = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (dif[i - 1] % 2 != temp1[i - 1] % 2)
        {
            cnt1++;
            temp1[i - 1]++;
            temp1[i]++;
            temp1[i + 1]++;
        }
    }
    if ((dif[n - 2] % 2) == (temp1[n - 2] % 2) && (dif[n - 1] % 2) == (temp1[n - 1] % 2))
    {
        ans = min(ans, cnt1);
    }
    else if ((dif[n - 2] % 2) != (temp1[n - 2] % 2) && (dif[n - 1] % 2) != (temp1[n - 1] % 2))
    {
        ans = min(ans, ++cnt1);
    }

    // 맨 처음꺼 누름
    vector<int> temp2(n, 0);
    temp2[0] = temp2[1] = 1;
    int cnt2 = 1;
    for (int i = 1; i < n - 1; i++)
    {
        if (dif[i - 1] % 2 != temp2[i - 1] % 2)
        {
            cnt2++;
            temp2[i - 1]++;
            temp2[i]++;
            temp2[i + 1]++;
        }
    }
    if ((dif[n - 2] % 2) == (temp2[n - 2] % 2) && (dif[n - 1] % 2) == (temp2[n - 1] % 2))
    {
        ans = min(ans, cnt2);
    }
    else if ((dif[n - 2] % 2) != (temp2[n - 2] % 2) && (dif[n - 1] % 2) != (temp2[n - 1] % 2))
    {
        ans = min(ans, ++cnt2);
    }

    if (ans == INT32_MAX)
        cout << -1;
    else
        cout << ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}