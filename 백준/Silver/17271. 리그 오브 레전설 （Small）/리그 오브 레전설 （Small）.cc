#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    dp[1] = 1, dp[m] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = (dp[i] + dp[i - 1]) % 1000000007;
        if (i - m >= 0) dp[i] = (dp[i] + dp[i - m]) % 1000000007;
    }

    cout << dp[n];

    return 0;
}