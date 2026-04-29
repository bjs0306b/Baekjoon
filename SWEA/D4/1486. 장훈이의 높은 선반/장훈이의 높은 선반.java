#include <bits/stdc++.h>
using namespace std;

int n,m; 
int ans;
vector<int> v;
void dfs(int dep, int sum){
    if(n == dep){
        if(sum >= m){
            ans = min(ans, sum);
        }
        return;
    }
    dfs(dep+1, sum);
    dfs(dep+1, sum+v[dep]);
}

void solve(){
    ans = INT32_MAX;
    cin >> n >> m;
    v.resize(n); for(int i=0;i<n;i++) cin >> v[i];
    dfs(0, 0);
    cout << ans - m << '\n';
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