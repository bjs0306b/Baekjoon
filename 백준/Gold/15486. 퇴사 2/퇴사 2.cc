#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    vector<int> dp(n+1, 0);

    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, dp[i]);
        dp[i] = ans;
        if(i+v[i].first <= n ) dp[i+v[i].first] = max(dp[i]+v[i].second, dp[i+v[i].first]);
    }
    cout << max(ans, dp[n]);

    return 0;
}