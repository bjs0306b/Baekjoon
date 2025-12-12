#include <bits/stdc++.h>
using namespace std;

long long solve(){
    long long n; cin >> n;
    vector<long long> v(n); for(long long i=0;i<n;i++) cin >> v[i];
    vector<long long> pre_sum(n); pre_sum[0] = v[0];
    for(long long i=1;i<n;i++) pre_sum[i] = pre_sum[i-1] + v[i];
    long long div_4 = pre_sum[n-1] / 4;
    vector<long long> dp(4, 0);

    if(pre_sum[n-1] % 4){
        return 0;
    }

    for(long long i=0;i<n-1;i++){
        if(pre_sum[i] == div_4*3){
            dp[2] += dp[1];
        }
        if(pre_sum[i] == div_4*2){
            dp[1] += dp[0];
        }
        if(pre_sum[i] == div_4){
            dp[0]++;
        } 
    }

    return dp[2];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cout << solve();
    
    return 0;
}