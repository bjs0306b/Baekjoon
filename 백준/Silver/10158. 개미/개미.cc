#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int fc = c, fd = d, fe = e;
    int dirx = 1, diry = 1;

    if (a == b && c == d)
        e %= 2 * a;
    else
    {
        int mn = min(abs(a - c), abs(b - d));
        e -= mn;
        c += mn;
        d += mn;
    }

    bool arr[2][2] = {{0, 0}, {0, 0}};
    int cnt = 0;
    if (arr[(dirx + 1) / 2][(diry + 1) / 2] == 0)
    {
        arr[(dirx + 1) / 2][(diry + 1) / 2] = 1;
        cnt++;
    }

    for (;;)
    {
        if (c == 0 || c == a)
            dirx *= -1;
        if (d == 0 || d == b)
            diry *= -1;

        if (arr[(dirx + 1) / 2][(diry + 1) / 2] == 0)
        {
            arr[(dirx + 1) / 2][(diry + 1) / 2] = 1;
            cnt++;
        }
        if (cnt == 4 && c == fc && d == fd)
            e %= (fe - e);

        int mn1, mn2;
        if (dirx == 1)
            mn1 = a - c;
        else
            mn1 = c;
        if (diry == 1)
            mn2 = b - d;
        else
            mn2 = d;
        int mn = min(mn1, mn2);

        if (mn <= e)
        {
            e -= mn;
            c += dirx * mn;
            d += diry * mn;
        }
        else
        {
            c += dirx * e;
            d += diry * e;
            break;
        }
    }
    cout << c << " " << d;

    return 0;
}