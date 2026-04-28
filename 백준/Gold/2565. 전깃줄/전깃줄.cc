#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
 
    vector<int> v2(n); for(int i=0;i<n;i++) v2[i] = v[i].second;

    int mx = 0;
    vector<int> dp(n, 1);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--) if(v2[i] > v2[j]) dp[i] = max(dp[i], dp[j]+1);
        mx = max(mx, dp[i]);
    }
    cout << n - mx;
    
    return 0;
}