#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n+1); for(int i=1;i<=n;i++) cin >> v[i];

    vector<int> dp(n+1, INT32_MAX); dp[0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            dp[j+i] = min(dp[j+i], dp[j] + v[i]);
        }
    }

    cout << dp[n];

    return 0;
}