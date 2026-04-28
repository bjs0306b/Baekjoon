#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int a, b;
    for (;;)
    {
        cin >> s >> a >> b;
        if (s == "#" && a == 0 && b == 0)
            break;
        if (a > 17 || b >= 80)
            cout << s << " Senior\n";
        else
            cout << s << " Junior\n";
    }

    return 0;
}