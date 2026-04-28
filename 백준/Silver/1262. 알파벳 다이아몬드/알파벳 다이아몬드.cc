#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            int temp = abs(i % (2 * n - 1) - n + 1) + abs(j % (2 * n - 1) - n + 1);
            if (temp > n - 1)
                cout << ".";
            else
            {
                temp %= 26;
                char c = 'a' + temp;
                cout << c;
            }
        }
        cout << "\n";
    }

    return 0;
}