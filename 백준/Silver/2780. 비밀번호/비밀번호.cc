#include <bits/stdc++.h>
using namespace std;

int dp[1001][10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<10;i++) dp[1][i] = 1;
    for(int i=2;i<1001;i++){
        dp[i][0] = dp[i-1][7];
        dp[i][1] = (dp[i-1][2] + dp[i-1][4])%1234567;
        dp[i][2] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][5])%1234567;
        dp[i][3] = (dp[i-1][2] + dp[i-1][6])%1234567;
        dp[i][4] = (dp[i-1][1] + dp[i-1][5] + dp[i-1][7])%1234567;
        dp[i][5] = (dp[i-1][2] + dp[i-1][4] + dp[i-1][6]+ dp[i-1][8])%1234567;
        dp[i][6] = (dp[i-1][3] + dp[i-1][5] + dp[i-1][9])%1234567;
        dp[i][7] = (dp[i-1][0] + dp[i-1][4] + dp[i-1][8])%1234567;
        dp[i][8] = (dp[i-1][9] + dp[i-1][5] + dp[i-1][7])%1234567;
        dp[i][9] = (dp[i-1][6] + dp[i-1][8] )%1234567;
    }

    while(n--){
        int num; cin >> num;
        int ans = 0; for(int i=0;i<10;i++) ans += dp[num][i];
        cout << ans % 1234567 << "\n";
    }
    
    return 0;
}