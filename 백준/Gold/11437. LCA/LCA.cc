#include <bits/stdc++.h>
using namespace std;

int n;
int dep[100001];
int parent[100001][18];
vector<int> v[100001];

void input(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(int cur, int d, int pre){
    dep[cur] = d;
    for(auto k : v[cur]){
        if(k == pre) continue;
        parent[k][0] = cur;
        dfs(k, d+1, cur);
    }
}

int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a,b);

    for(int i=17;i>=0;i--){ // 깊이 같게 하기
        if(dep[a] - (1 << i) >= dep[b]){
            a = parent[a][i];
        }
    }

    if(a == b) return a; 

    for(int i=17;i>=0;i--){
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    
    return parent[a][0];
}

void solve(){
    dfs(1, 0, -1); // 바로 위의 부모 저장
    
    for(int i=1;i<18;i++){
        for(int j=1;j<=n;j++){
            if(parent[j][i-1] != 0) parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }

    int m; cin >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        cout << lca(a,b) << "\n";
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}