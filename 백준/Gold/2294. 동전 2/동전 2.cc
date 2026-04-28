#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<int> dp(10001, 10000000);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10001 - A[i]; j++)
        {
            dp[j + A[i]] = min(dp[j + A[i]], dp[j] + 1);
        }
    }
    if (dp[k] == 10000000)
        cout << -1;
    else
        cout << dp[k];

    return 0;
}