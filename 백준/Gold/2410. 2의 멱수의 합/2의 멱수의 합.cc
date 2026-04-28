#include <bits/stdc++.h>
using namespace std;

int n;

void input(){
    cin >> n;
}

void solve(){
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for(int i=1;i<=n;i*=2){
        for(int j=i;j<=n;j++){
            dp[j] = (dp[j] + dp[j-i])%1000000000;
        }
    }
    cout << dp[n];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}