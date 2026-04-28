#include <bits/stdc++.h>
using namespace std;

int n,m, idx;
vector<int> v[10001];
int dfsn[10001];
bool is_ans[10001];

void input(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int dfs(int num, bool is_root){
    dfsn[num] = ++idx;
    int ret = idx;
    int child_cnt = 0;

    for(auto k : v[num]){
        if(dfsn[k]){
            ret = min(ret, dfsn[k]);
            continue;
        }

        child_cnt++;
        int next_ret = dfs(k, false);
        if(!is_root && next_ret >= dfsn[num]) is_ans[num] = true;
        ret = min(ret, next_ret);
    }
    if(is_root && child_cnt > 1) is_ans[num] = true;
    return ret;
}

void solve(){
    for(int i=1;i<=n;i++){
        dfs(i, true);
    }

    vector<int> ans;
    for(int i=1;i<=n;i++) if(is_ans[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    for(auto k : ans) cout << k << " ";
}

int main(){
    input();
    solve();
}