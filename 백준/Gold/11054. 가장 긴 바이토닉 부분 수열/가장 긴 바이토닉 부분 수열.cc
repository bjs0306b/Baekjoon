#include<bits/stdc++.h>
using namespace std;

int dp[1001][2];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int arr[n]; for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i] && dp[j][0] >= dp[i][0]) dp[i][0] = dp[j][0] + 1;
            else if(arr[j] > arr[i]){
                int temp = max(dp[j][0], dp[j][1]);
                if(temp >= dp[i][1]) dp[i][1] = temp + 1;
            } 
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans + 1;
    
    return 0;
}