#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2,s3; cin >> s1 >> s2 >> s3;
    int x= s1.size(), y = s2.size(), z = s3.size();

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            for(int k=1;k<=z;k++){
                if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else{
                    dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),max(max(dp[i][j][k-1],dp[i-1][j-1][k]),max(dp[i-1][j][k-1],dp[i][j-1][k-1])));
                }
            }
        }
    }
    cout << dp[x][y][z];

    return 0;
}