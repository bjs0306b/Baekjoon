#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b;
    cin >> a >> b;
    long long ans = 100 * b / a;
    if (ans >= 99)
    {
        cout << -1;
        return 0;
    }
    long long m, s = 0, e = a, ansans = 0;
    while (s <= e)
    {
        m = (s + e) / 2;
        long long temp = 100 * (b + m) / (a + m);
        if (temp > ans)
        {
            e = m - 1;
            ansans = m;
        }
        else
            s = m + 1;
    }
    cout << ansans;

    return 0;
}