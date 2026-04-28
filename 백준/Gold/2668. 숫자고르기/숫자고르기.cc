#include <bits/stdc++.h>
using namespace std;

set<int> ans;
vector<int> v;
bool visited[101];

void dfs(int start, int cur, vector<int> A){
    if(visited[cur]) return;
    if(start == cur){
        for(auto &k : A) ans.insert(k);
        return;
    }
    visited[cur] = true;
    A.push_back(cur);
    dfs(start, v[cur], A);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    v.resize(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) visited[j] = false;

        vector<int> temp;
        temp.push_back(v[i]);
        dfs(i, v[i], temp);
    }

    cout << ans.size() << "\n";
    for(auto &k : ans) cout << k << "\n";

    return 0;
}