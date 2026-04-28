#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n; cin >> n;
    vector<pair<int,int>> v(n); for(int i=0;i<n;i++){int a,b; cin >> a >> b; v[i] = {a,b};}
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=2;i<=n;i++){ // length
        for(int j=0;j<n-i+1;j++){ // start
            int end = j + i - 1;
            dp[j][end] = INT32_MAX;
            for(int k = 0; k < i-1; k++){
                dp[j][end] = min(dp[j][end], dp[j][j+k] + dp[j+k+1][end] + v[j].first * v[end].second * v[j+k].second);
            }
        }
    }
    cout << dp[0][n-1];
    
    return 0;
}