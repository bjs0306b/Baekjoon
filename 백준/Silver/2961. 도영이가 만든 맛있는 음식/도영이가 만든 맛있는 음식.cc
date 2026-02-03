#include <bits/stdc++.h>
using namespace std;

int n;
int ans = INT32_MAX;
vector<pair<int,int>> v;
void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }
}

void dfs(int dep, int cnt, int sour, int bitter){
    if(dep == n){
        if(cnt != 0){
            ans = min(ans, abs(sour - bitter));
        }
        return;
    }

    dfs(dep+1, cnt+1, sour * v[dep].first, bitter + v[dep].second);
    dfs(dep+1, cnt, sour, bitter);
}

void solve(){
    dfs(0, 0, 1, 0);
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();
}