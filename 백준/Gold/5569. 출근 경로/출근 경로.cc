#include <bits/stdc++.h>
using namespace std;
int dp[100][100][4];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b; cin >> a >> b;
    for(int i=0;i<a;i++) dp[i][0][3] = 1;
    for(int i=0;i<b;i++) dp[0][i][0] = 1;

    for(int i=1;i<a;i++){
        for(int j=1;j<b;j++){
            dp[i][j][0] = (dp[i][j-1][0] + dp[i][j-1][2])%100000;
            dp[i][j][1] = dp[i-1][j][0];
            dp[i][j][2] = dp[i][j-1][3];
            dp[i][j][3] = (dp[i-1][j][1] + dp[i-1][j][3])%100000;
        }
    }
    
    int ans = (dp[a-1][b-1][0] + dp[a-1][b-1][1] + dp[a-1][b-1][2] + dp[a-1][b-1][3]) % 100000;

    cout << ans;

    return 0;
}