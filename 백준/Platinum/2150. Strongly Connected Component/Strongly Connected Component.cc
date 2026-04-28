#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
vector<vector<int>> groups;
stack<int> group;
bool grouped[10001];
int check[10001];
int num = 0;
int n,m;

int dfs(int idx){
    check[idx] = ++num;
    group.push(idx);

    int p = check[idx];
    for(int i=0;i<v[idx].size();i++){
        int c = v[idx][i];
        if(!check[c]) p = min(p, dfs(c));
        else if(!grouped[c]) p = min(p, check[c]);
    }

    if(p == check[idx]){
        vector<int> temp;
        for(;;){
            int t = group.top();
            group.pop();

            grouped[t] = true;
            temp.push_back(t);
            if(t == idx) break;
        }
        sort(temp.begin(), temp.end());
        groups.push_back(temp);
    }

    return p;
}

void input(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        if(!check[i]) dfs(i);
    }
    sort(groups.begin(), groups.end());
    cout << groups.size() << "\n";
    for(auto k : groups){
        for(auto kk : k) cout << kk << " ";
        cout << "-1\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    


    return 0;
}