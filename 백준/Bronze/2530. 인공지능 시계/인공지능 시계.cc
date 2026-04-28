#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int h, m, s;
    s = d % 60;
    m = (d / 60) % 60;
    h = d / 3600;
    a += h;
    b += m;
    c += s;
    if (c > 59)
    {
        c -= 60;
        b++;
    }
    if (b > 59)
    {
        b -= 60;
        a++;
    }
    a %= 24;
    cout << a << " " << b << " " << c;
    return 0;
}