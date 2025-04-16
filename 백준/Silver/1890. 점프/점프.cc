#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100][100];
long long dp[100][100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0) continue;

            if (i + arr[i][j] < n)
                dp[i + arr[i][j]][j] += dp[i][j];
            if (j + arr[i][j] < n)
                dp[i][j + arr[i][j]] += dp[i][j];
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}