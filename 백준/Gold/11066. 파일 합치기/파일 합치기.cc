#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n), sum(n+1); 
        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        sum[0] = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            sum[i+1] = sum[i] + v[i];
        }
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = v[i] + v[i+1];
        }

        for(int l=3;l<=n;l++){
            for(int s=0;s<n-l+1;s++){
                int e = s + l - 1;
                
                int mn = INT32_MAX;
                for(int i=s;i<e;i++){
                    mn = min(mn, dp[s][i] + dp[i+1][e] + sum[e+1] - sum[s]);
                }
                dp[s][e] = mn;
            }
        }

        cout << dp[0][n-1] << "\n";
    }
    
    return 0;
}