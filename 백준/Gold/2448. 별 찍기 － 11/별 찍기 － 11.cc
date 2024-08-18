#include <bits/stdc++.h>
using namespace std;

int k = 0;

bool arr[10000][10000];

void tri(int level, int x, int y)
{
    int temp = 3;
    for (int i = 1; i < level; i++)
        temp *= 2;

    if (level == 0)
    {
        arr[x][y] = 1;
        arr[x + 1][y - 1] = 1;
        arr[x + 1][y + 1] = 1;
        for (int i = 0; i < 5; i++)
            arr[x + 2][y - 2 + i] = 1;
        return;
    }
    else
    {
        tri(level - 1, x, y);

        tri(level - 1, x + temp, y + temp);

        tri(level - 1, x + temp, y - temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n != 3)
    {
        n /= 2;
        k++;
    }
    int a = 3, b = 5;
    for (int i = 0; i < k; i++)
    {
        a *= 2;
        b = 2 * b + 1;
    }
    // cout << k << " " << a <<  " " << b << "\n";

    tri(k, 0, b / 2);

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (arr[i][j])
                cout << "*";
            else
                cout << " ";
        }
        cout << '\n';
    }

    return 0;
}