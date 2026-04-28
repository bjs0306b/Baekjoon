#include <bits/stdc++.h>
using namespace std;

long long ans = -1;
long long n, m;
long long A[9][9];

void dfs2(long long x, long long y, long long dx, long long dy)
{
    long long i, j;
    long long temp = 0;
    for (i = x, j = y; i >= 0 && i < n && j >= 0 && j < m; i += dx, j += dy)
    {
        temp *= 10;
        temp += A[i][j];

        if ((long long)sqrt(temp) * (long long)sqrt(temp) == temp) ans = max(ans, temp);

        if (dx == 0 && dy == 0)
            break;
    }
}

void dfs1(long long x, long long y)
{
    for (long long i = -x; i < n - x; i++)
        for (long long j = -y; j < m - y; j++)
        {
            dfs2(x, y, i, j);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (long long i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (long long j = 0; j < m; j++)
        {
            long long num = s[j] - '0';
            A[i][j] = num;
        }
    }

    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < m; j++)
            dfs1(i, j);

    cout << ans;

    return 0;
}