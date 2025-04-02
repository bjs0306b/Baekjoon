#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001]; // 각각 vb, va를 이 만큼 제거했을 때의 최대값. -1 방문하지 않았거나 불가능. 0 방문 가능함.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> va(n), vb(n);
    for(int i=0;i<n;i++) cin >> va[i];
    for(int i=0;i<n;i++) cin >> vb[i];

    for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = -1; 

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] != -1 && vb[i] < va[j]) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + vb[i]);
            if(dp[i][j] != -1) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]);
            if(dp[i][j] != -1) dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    int ans = 0;
    for(int i=0;i<=n;i++) ans = max(ans, dp[n][i]);
    for(int i=0;i<=n;i++) ans = max(ans, dp[i][n]);
    cout << ans;

    return 0;
}