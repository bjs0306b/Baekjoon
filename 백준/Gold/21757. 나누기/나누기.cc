#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long n; cin >> n;
    vector<long long> v(n); for(long long i=0;i<n;i++) cin >> v[i];
    vector<long long> pre_sum(n); pre_sum[0] = v[0];
    for(long long i=1;i<n;i++) pre_sum[i] = pre_sum[i-1] + v[i];
    long long div_4 = pre_sum[n-1] / 4;
    long long dp[n][4]; for(long long i=0;i<n;i++) for(long long j=0;j<4;j++) dp[i][j] = 0;
    if(pre_sum[0] == div_4 ) dp[0][0] = 1;

    if(pre_sum[n-1] % 4){
        cout << 0;
        return 0;
    }

    if(pre_sum[n-1] == 0){
        int cnt = 0;
        for(int i=0;i<n;i++) if(pre_sum[i] == 0) cnt++;
        if(cnt < 4) cout << 0;
        else cout << (cnt-1)*(cnt-2)*(cnt-3)/6;
        return 0;
    }

    for(long long i=1;i<n;i++){
        for(long long j=0;j<4;j++) dp[i][j] = dp[i-1][j];

        if(pre_sum[i] % div_4 == 0){
            long long temp = pre_sum[i] / div_4;
            if(temp == 1) dp[i][0]++;
            else if(temp < 4) dp[i][temp-1] += dp[i-1][temp-2];
        }
    }

    cout << dp[n-1][2];

    return 0;
}