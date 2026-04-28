#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    long long dp[n+1][3];
    dp[1][0] = 0, dp[1][1] = 1, dp[1][2] = 1; // 0으로 시작은 제외
    
    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%1000000009;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%1000000009;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%1000000009;
    }

    cout << dp[n][0];

    return 0;
}