#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        int n;
        cin >> n;

        int a, b, c;
        a = 0;
        b = 1;
        c = a + b;
        if (n)
        {
            for (int i = 1; i < n; i++)
            {
                a = b;
                b = c;
                c = a + b;
            }
            cout << a << " " << b << "\n";
        }
        else
            cout << 1 << " " << 0 << "\n";
    }

    return 0;
}