#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, bridge[2]; cin >> s >> bridge[0] >> bridge[1];
    int dp[2][bridge[0].size()][s.size()];
    for(int i=0;i<2;i++) for(int j=0;j<bridge[0].size();j++) for(int k=0;k<s.size();k++) dp[i][j][k] = 0;
    for(int i=0;i<bridge[0].size();i++){
        for(int j=0;j<2;j++){
            if(bridge[j][i] == s[0]){
                dp[j][i][0] = 1;
            }
        }
    }

    for(int k=1;k<s.size();k++){
        for(int i=0;i<bridge[0].size();i++){
            for(int j=0;j<2;j++){
                if(bridge[j][i] == s[k]){
                    if(j == 0){
                        for(int l = i-1; l >= 0; l--){
                            dp[j][i][k] += dp[1][l][k-1];
                        } 
                    }
                    else if(j == 1){
                        for(int l = i-1; l >= 0; l--){
                            dp[j][i][k] += dp[0][l][k-1];
                        } 
                    }   
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<bridge[0].size();i++){
        for(int j=0;j<2;j++){
            ans += dp[j][i][s.size()-1];
        }
    }
    cout << ans;

    return 0;
}