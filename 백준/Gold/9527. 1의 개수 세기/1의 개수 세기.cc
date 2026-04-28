#include <bits/stdc++.h>
using namespace std;

long long func(long long num)
{
    long long temp = 1;
    long long r = 0;
    while (temp < num)
    {
        r += num / (2 * temp) * temp;
        if (num % (2 * temp) - temp > 0)
            r += num % (2 * temp) - temp;
        temp *= 2;
        // cout << r << " ";
    }

    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long s, e;
    cin >> s >> e;

    cout << func(e + 1) - func(s);

    return 0;
}