#include<bits/stdc++.h>
using namespace std;

int dp[100001][5][5];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; 
    
    vector<int> vec;
    for(;;){
        cin >> n; if(n==0) break;
        vec.push_back(n);
    }
    for(int i=0;i<vec.size();i++) for(int j=0;j<5;j++) for(int k=0;k<5;k++) dp[i][j][k] = 300001;
    
    dp[0][vec[0]][0] = dp[0][0][vec[0]] = 2;

    for(int i=1;i<vec.size();i++){
        int num = vec[i];
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(k == 0)
                    dp[i][num][j] = min(dp[i][num][j], dp[i-1][k][j] + 2);
                else if(k == num) dp[i][num][j] = min(dp[i][num][j], dp[i-1][k][j] + 1);
                else if(abs(k-num) == 2) dp[i][num][j] = min(dp[i][num][j], dp[i-1][k][j] + 4);
                else dp[i][num][j] = min(dp[i][num][j], dp[i-1][k][j] + 3);
            }
            for(int k=0;k<5;k++){
                if(k == 0)
                    dp[i][j][num] = min(dp[i][j][num], dp[i-1][j][k] + 2);
                else if(k == num) dp[i][j][num] = min(dp[i][j][num], dp[i-1][j][k] + 1);
                else if(abs(k-num) == 2) dp[i][j][num] = min(dp[i][j][num], dp[i-1][j][k] + 4);
                else dp[i][j][num] = min(dp[i][j][num], dp[i-1][j][k] + 3);
            }
        }
    }
    int ans = 300001;
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) ans = min(ans, dp[vec.size()-1][i][j]);
    cout << ans;

    // for(int i=0;i<vec.size();i++){
    //     for(int j=0;j<5;j++){
    //         for(int k=0;k<5;k++){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    // }
    
    return 0;
}