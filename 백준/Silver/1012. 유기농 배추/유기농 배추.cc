#include <iostream>
#include <algorithm>
using namespace std;

int arr[50][50];

void clean(int i, int j)
{
    if (arr[i + 1][j] && i + 1 < 50)
    {
        arr[i + 1][j] = 0;
        clean(i + 1, j);
    }
    if (arr[i - 1][j] && 0 <= i - 1)
    {
        arr[i - 1][j] = 0;
        clean(i - 1, j);
    }
    if (arr[i][j + 1] && j + 1 < 50)
    {
        arr[i][j + 1] = 0;
        clean(i, j + 1);
    }
    if (arr[i][j - 1] && 0 <= j - 1)
    {
        arr[i][j - 1] = 0;
        clean(i, j - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 50; j++)
            arr[i][j] = 0;
    for (int k = 0; k < n; k++)
    {
        int a, b, c, cnt = 0;
        cin >> a >> b >> c;
        for (int i = 0; i < c; i++)
        {
            int d, e;
            cin >> d >> e;
            arr[d][e] = 1;
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (arr[i][j])
                {
                    cnt++;
                    clean(i, j);
                }
            }
        }
        cout << cnt << "\n";
        for (int i = 0; i < 50; i++)
            for (int j = 0; j < 50; j++)
                arr[i][j] = 0;
    }

    return 0;
}