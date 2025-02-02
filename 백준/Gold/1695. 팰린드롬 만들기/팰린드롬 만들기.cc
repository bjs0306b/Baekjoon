#include <bits/stdc++.h>
using namespace std;

int dp[5000][5000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++)
        if (v[i] == v[i + 1])
            dp[i][i + 1] = 2;
        else
            dp[i][i + 1] = 1;

    for (int len = 3; len <= n; len++)
    {
        for (int s = 0; s < n - len + 1; s++)
        {
            int e = s + len - 1;
            if (v[s] == v[e])
                dp[s][e] = dp[s + 1][e - 1] + 2;
            else
                dp[s][e] = max(max(dp[s][e-1], dp[s+1][e]), dp[s + 1][e - 1]);
        }
    }

    cout << n - dp[0][n-1];
            

    return 0;
}