#include <bits/stdc++.h>
using namespace std;

int ans(){
    int n; cin >> n;
    if(n%2) return 0;

    int dp[n/2][3]; dp[0][0] = dp[0][1] = dp[0][2] = 1;

    for(int i=1;i<n/2;i++){
        dp[i][0] = dp[i-1][0]*2 + dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][1]*2 + dp[i-1][2];
        dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
    }

    return dp[n/2-1][0]+dp[n/2-1][1]+dp[n/2-1][2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << ans();
    
    return 0;
}