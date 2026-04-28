#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == 15)
        a = 0;
    if (c == 19)
        c = 0;
    long long i;
    for (i = b; i % 15 != a || i % 19 != c; i += 28);
    cout << i;

    return 0;
}