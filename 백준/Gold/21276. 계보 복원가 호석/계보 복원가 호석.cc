#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> v;
map<string, int> cnt;
map<string, set<string>> mp;
map<string, set<string>> ans;
void input(){
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        cnt[v[i]] = 0;
    }
    sort(v.begin(), v.end());
    cin >> m;
    for(int i=0;i<m;i++){
        string a, b;
        cin >> a >> b;
        mp[b].insert(a);
        cnt[a]++;
    }
}

void solve(){
    queue<string> q;
    set<string> s;
    for(auto k : cnt){
        if(k.second == 0){
            q.push(k.first);   
            s.insert(k.first);
        }       
    }
    
    cout << s.size() << "\n";
    for(auto k : s) cout << k << " ";
    cout << "\n";

    while(!q.empty()){
        string f = q.front();
        q.pop();

        for(auto k : mp[f]){
            if(--cnt[k] == 0){
                ans[f].insert(k);
                q.push(k);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << v[i] << " " << ans[v[i]].size() << " ";
        for(auto k : ans[v[i]]) cout << k << " ";
        cout << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}