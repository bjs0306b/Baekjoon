#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, aa, aaa, b, bb, bbb, sum, i;
    cin >> a >> b;
    sum = 0, aa = 0, bb = 0;
    while (aa * (aa + 1) / 2 < a)
        aa++;
    while (bb * (bb + 1) / 2 < b)
        bb++;
    aaa = aa * (aa + 1) / 2;
    bbb = bb * (bb - 1) / 2;
    if (aa != bb)
    {
        sum = sum + (aaa - a + 1) * aa + (b - bbb) * bb;
        for (i = aa + 1; i < bb; i++)
            sum += i * i;
    }
    else{
        sum = aa*(b-a+1);
    }
    cout << sum;

    return 0;
}