#include <bits/stdc++.h>
using namespace std;

long long dp[33][33];
long long pre_sum_dp[33][33];
long long N,L,I; 

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> L >> I;

    dp[0][0] = 1;
    for(long long i=1;i<=N;i++){
        for(long long j=0;j<=L;j++){
            if(j > 0) dp[i][j] += dp[i-1][j-1];
            dp[i][j] += dp[i-1][j];
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }

    for(long long i=0;i<=N;i++){
        pre_sum_dp[i][0] = dp[i][0];
        for(long long j=1;j<=L;j++){
            pre_sum_dp[i][j] = pre_sum_dp[i][j-1] + dp[i][j];
            // cout << pre_sum_dp[i][j] << " ";
        }
        // cout << "\n";
    }

    int temp = L;
    for(long long i=N-1;i>=0;i--){
        if(I > pre_sum_dp[i][temp]){
            I -= pre_sum_dp[i][temp--];
            cout << "1";
        }
        else cout << "0";
    }

    

    return 0;
}