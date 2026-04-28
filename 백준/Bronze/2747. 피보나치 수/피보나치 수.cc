#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n < 2)
        cout << n;
    else
    {
        int a, b, c;
        a = 0;
        b = 1;
        c = 1;
        for (int i = 0; i < n - 2; i++)
        {
            a = b;
            b = c;
            c = a + b;
        }
        cout << c;
    }

    return 0;
}