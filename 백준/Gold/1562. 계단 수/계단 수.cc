#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int dp[n][10][1024];

    for(int i=1;i<=9;i++){
        int temp = pow(2,i);
        dp[0][i][temp] = 1;
    }

    for(int i=0;i<n-1;i++){
        
        for(int j=0;j<10;j++){
            for(int k=0;k<1024;k++){
                if(j == 0){
                    dp[i+1][1][k|2] = (dp[i+1][1][k|2] + dp[i][0][k])%1000000000;
                }
                else if(j == 9){
                    dp[i+1][8][k|(1<<8)] = (dp[i+1][8][k|(1<<8)] + dp[i][9][k])%1000000000;
                }
                else{
                    dp[i+1][j-1][k|(1<<(j-1))] = (dp[i+1][j-1][k|(1<<(j-1))] + dp[i][j][k])%1000000000;
                    dp[i+1][j+1][k|(1<<(j+1))] = (dp[i+1][j+1][k|(1<<(j+1))] + dp[i][j][k])%1000000000;
                }
            }
        }
    }
    
    long long ans = 0;

    for(int i=0;i<10;i++){
        ans += dp[n-1][i][1023];
    }
    cout << ans %1000000000;


    return 0;
}