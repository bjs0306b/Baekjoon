#include <bits/stdc++.h>
using namespace std;

int n, m;

bool solve(){
    cin >> n;
    double temp; cin >> temp;
    m = temp * 100 + 0.5;

    if(n == 0 && m == 0) return false;
    
    vector<int> dp(m+1, 0);
    int a,b;
    for(int i=0;i<n;i++){
        cin >> a >> temp;
        b = temp * 100 + 0.5;

        for(int j=b;j<=m;j++){
            dp[j] = max(dp[j], dp[j-b] + a);
        }
    }
    cout << dp[m] << "\n";
    return true;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    while(solve());

    return 0;
}