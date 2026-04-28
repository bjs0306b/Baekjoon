#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    for (int i = 1;; i++)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        int num = c / b * a;
        int num2 = (a < c % b) ? a : c % b;
        cout << "Case " << i << ": " << num + num2 << "\n";
    }

    return 0;
}