#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,ans=0; cin >> n >> m;
    bool A[n][m]; int dp[n][m];
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '1'){
                ans = 1;
                A[i][j] = true;
            }
            else A[i][j] = false;
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = A[i][j];
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(A[i][j]){
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << dp[i][j];
    //     }
    //     cout << "\n";
    // }

    cout << ans * ans;
     
    
    return 0;
}