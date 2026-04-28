#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int num = 0;
    while (b)
    {
        num++;
        if (a % num == 0)
            b--;
        if (num > a)
        {
            num = 0;
            break;
        }
    }
    cout << num;

    return 0;
}