#include <bits/stdc++.h>
using namespace std;

long long n, m, a[5][5];
long long ans[5][5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    m--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long num;
            cin >> num;
            num %= 1000;
            a[i][j] = ans[i][j] = num;
        }
    }
    while (m)
    {
        long long temp[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp[i][j] = 0;
        if (m % 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        temp[i][j] += (ans[i][k] * a[k][j]) % 1000;
                        temp[i][j] %= 1000;
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    ans[i][j] = temp[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp[i][j] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    temp[i][j] += (a[i][k] * a[k][j]) % 1000;
                    temp[i][j] %= 1000;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = temp[i][j];
            }
        }
        m /= 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}