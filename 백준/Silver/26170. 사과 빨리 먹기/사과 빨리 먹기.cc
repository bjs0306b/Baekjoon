#include <bits/stdc++.h>
using namespace std;

int arr[5][5];

int mn = 100;

void func(int a, int b, int dis, int apples)
{
    if (dis >= mn)
        return;
    if (arr[a][b] == 1)
        apples++;
    if (apples == 3)
    {
        mn = min(mn, dis);
        return;
    }

    if (a < 4 && arr[a+1][b] != -1)
    {
        int temp = arr[a][b];
        arr[a][b] = -1;
        func(a + 1, b, dis + 1, apples);
        arr[a][b] = temp;
    }
    if (b < 4 && arr[a][b+1] != -1)
    {
        int temp = arr[a][b];
        arr[a][b] = -1;
        func(a, b + 1, dis + 1, apples);
        arr[a][b] = temp;
    }
    if (a > 0 && arr[a-1][b] != -1)
    {
        int temp = arr[a][b];
        arr[a][b] = -1;
        func(a - 1, b, dis + 1, apples);
        arr[a][b] = temp;
    }
    if (b > 0 && arr[a][b-1] != -1)
    {
        int temp = arr[a][b];
        arr[a][b] = -1;
        func(a, b - 1, dis + 1, apples);
        arr[a][b] = temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    func(x, y, 0, 0);

    if (mn == 100)
        cout << -1;
    else
        cout << mn;

    return 0;
}