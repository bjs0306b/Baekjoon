#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];  // dp[n][k][마지막 비트]

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[1][0][0] = dp[1][0][1] = 1;
    for(int i=2;i<101;i++){
        for(int j=0;j<101;j++){
            dp[i][j][0] += (dp[i-1][j][0] + dp[i-1][j][1]);
            dp[i][j][1] += dp[i-1][j][0];
            dp[i][j+1][1] += dp[i-1][j][1];
        }
    }

    int n;
    cin >> n;

    while(n--){
        int a,b; cin >> a >> b;
        cout << dp[a][b][0] + dp[a][b][1] << "\n";
    }

    return 0;
}