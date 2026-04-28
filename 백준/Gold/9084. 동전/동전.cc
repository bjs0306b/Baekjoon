#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n); for(int i=0;i<n;i++) cin >> v[i];
        int m; cin >> m;

        for(int i=0;i<=m;i++) dp[i] = 0;
        for(int i=0;i<v.size();i++){
            dp[v[i]]++;
            for(int j=0;j<=m-v[i];j++){
                dp[j+v[i]] += dp[j] ; 
            }
        }
        cout << dp[m] << "\n";
    }

    return 0;
}