#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long A[50][50];
long long row_sum[50][50];
long long total_sum[50][50];

long long ans = 0;

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
            A[i][j] = s[j] - '0';
    }
    for (long long i = 0; i < n; i++)
    {
        row_sum[i][0] = A[i][0];
        for (long long j = 1; j < m; j++)
        {
            row_sum[i][j] = row_sum[i][j - 1] + A[i][j];
        }
    }
    for (long long j = 0; j < m; j++)
    {
        total_sum[0][j] = row_sum[0][j];
        for (long long i = 1; i < n; i++)
        {
            total_sum[i][j] = total_sum[i - 1][j] + row_sum[i][j];
        }
    }

    if (n == 1)
    {
        for (long long i = 0; i < m - 2; i++)
        {
            for (long long j = i + 1; j < m - 1; j++)
            {

                ans = max(ans, total_sum[0][i] * (total_sum[0][j] - total_sum[0][i]) * (total_sum[0][m - 1] - total_sum[0][j]));
            }
        }
    }
    else if (m == 1)
    {
        for (long long i = 0; i < n - 2; i++)
        {
            for (long long j = i + 1; j < n - 1; j++)
            {

                ans = max(ans, total_sum[i][0] * (total_sum[j][0] - total_sum[i][0]) * (total_sum[n - 1][0] - total_sum[j][0]));
            }
        }
    }
    else
    {
        for (long long i = 0; i < m - 2; i++)
        {
            for (long long j = i + 1; j < m - 1; j++)
            {

                ans = max(ans, total_sum[n - 1][i] * (total_sum[n - 1][j] - total_sum[n - 1][i]) * (total_sum[n - 1][m - 1] - total_sum[n - 1][j]));
            }
        }
        for (long long i = 0; i < n - 2; i++)
        {
            for (long long j = i + 1; j < n - 1; j++)
            {

                ans = max(ans, total_sum[i][m - 1] * (total_sum[j][m - 1] - total_sum[i][m - 1]) * (total_sum[n - 1][m - 1] - total_sum[j][m - 1]));
            }
        }
        for (long long i = 0; i < n - 1; i++)
        {
            for (long long j = 0; j < m - 1; j++)
            {
                ans = max(ans, total_sum[i][j] * (total_sum[n - 1][j] - total_sum[i][j]) * (total_sum[n - 1][m - 1] - total_sum[n - 1][j]));
                ans = max(ans, total_sum[i][j] * (total_sum[i][m - 1] - total_sum[i][j]) * (total_sum[n - 1][m - 1] - total_sum[i][m - 1]));
                ans = max(ans, total_sum[i][m-1] * (total_sum[n-1][j] - total_sum[i][j]) * (total_sum[n-1][m-1] - total_sum[i][m-1] - total_sum[n-1][j] + total_sum[i][j]));
                ans = max(ans, total_sum[n-1][j] * (total_sum[i][m-1] - total_sum[i][j]) * (total_sum[n-1][m-1] - total_sum[n-1][j] - total_sum[i][m-1] + total_sum[i][j]));
            }
        }

    }
    cout << ans;

    return 0;
}