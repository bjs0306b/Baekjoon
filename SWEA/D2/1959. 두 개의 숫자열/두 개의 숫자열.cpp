#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    int ans = INT32_MIN;
    if(n < m){
        for(int i=0;i<=m-n;i++){
            int temp = 0;
            for(int j=0;j<n;j++){
                temp += a[j]*b[j+i];
            }
            ans = max(ans, temp);
        }
    }
    else{
        for(int i=0;i<=n-m;i++){
            int temp = 0;
            for(int j=0;j<m;j++){
                temp += a[j+i]*b[j];
            }
            ans = max(ans, temp);
        }
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for(int i=1;i<=t;i++){
        cout << "#" << i << " ";
        solve();
    }

    return 0;
}