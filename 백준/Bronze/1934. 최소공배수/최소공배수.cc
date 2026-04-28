#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        int num = a;
        while (!(a % num == 0 && b % num == 0))
            num--;
        cout << a * b / num << "\n";
    }

    return 0;
}