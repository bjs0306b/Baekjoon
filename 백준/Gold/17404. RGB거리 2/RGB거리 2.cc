#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n][3]; for(int i=0;i<n;i++) for(int j=0;j<3;j++) cin >> arr[i][j];
    
    int ans = INT32_MAX;
    for(int i=0;i<3;i++){
        int dp[n][3];
        for(int j=0;j<n;j++) for(int k=0;k<3;k++) dp[j][k] =10000000;
        dp[0][i] = arr[0][i];
        
        for(int j=1;j<n;j++){
            dp[j][0] = min(dp[j][0], min(dp[j-1][1], dp[j-1][2]) + arr[j][0]);
            dp[j][1] = min(dp[j][1], min(dp[j-1][0], dp[j-1][2]) + arr[j][1]);
            dp[j][2] = min(dp[j][2], min(dp[j-1][0], dp[j-1][1]) + arr[j][2]);
        }

        for(int j=0;j<3;j++) if(i != j) ans = min(ans, dp[n-1][j]);
    }
    cout << ans;
    
    return 0;
}