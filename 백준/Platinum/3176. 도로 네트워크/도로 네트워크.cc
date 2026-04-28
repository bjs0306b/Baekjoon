#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> v[100001];
int parent[100001][18];
pair<int,int> max_and_min[100001][18];
int dep[100001];

void input(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
}

void dfs(int cur, int d, int pre){
    dep[cur] = d;
    for(auto k : v[cur]){
        if(k.first == pre) continue;
        parent[k.first][0] = cur;
        max_and_min[k.first][0] = {k.second, k.second};
        dfs(k.first, d+1, cur);
    }
}

void find_parent(){
    dfs(1, 0, -1);
    
    for(int j=1;j<18;j++){
        for(int i=1;i<=n;i++){
            if(parent[i][j-1] == 0) continue; 
            parent[i][j] = parent[parent[i][j-1]][j-1]; // parent[x][y] = x의 2^y번째 조상
            max_and_min[i][j] = {max(max_and_min[i][j-1].first, max_and_min[parent[i][j-1]][j-1].first), min(max_and_min[i][j-1].second, max_and_min[parent[i][j-1]][j-1].second)};
        }
    }
}

void lca(){
    pair<int,int> left_max_min = {0, INT32_MAX}, right_max_min = {0, INT32_MAX};
    int a,b; cin >> a >> b;

    if(dep[a] < dep[b]) swap(a,b);

    for(int i=17;i>=0;i--){
        if(dep[a] - (1 << i) >= dep[b]){
            left_max_min.first = max(left_max_min.first, max_and_min[a][i].first);
            left_max_min.second = min(left_max_min.second, max_and_min[a][i].second);
            a = parent[a][i];
        }
    }

    if(a == b){
        //cout << a << "\n";
        cout << left_max_min.second << " " << left_max_min.first << "\n";
        return;
    }

    for(int i=17;i>=0;i--){
        if(parent[a][i] != parent[b][i]){
            left_max_min.first = max(left_max_min.first, max_and_min[a][i].first);
            left_max_min.second = min(left_max_min.second, max_and_min[a][i].second);

            a = parent[a][i];

            right_max_min.first = max(right_max_min.first, max_and_min[b][i].first);
            right_max_min.second = min(right_max_min.second, max_and_min[b][i].second);

            b = parent[b][i];
        }
    }

    left_max_min.first = max(left_max_min.first, max_and_min[a][0].first);
    left_max_min.second = min(left_max_min.second, max_and_min[a][0].second);
    right_max_min.first = max(right_max_min.first, max_and_min[b][0].first);
    right_max_min.second = min(right_max_min.second, max_and_min[b][0].second);
    cout << min(left_max_min.second, right_max_min.second) << " " << max(left_max_min.first, right_max_min.first) << "\n";
    //cout << parent[a][0] << "\n";
}

void solve(){
    find_parent(); 
    
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<17;j++){
    //         cout << max_and_min[i][j].first << " " << max_and_min[i][j].second << '\n';
    //     }
    //     cout << '\n';
    // }

    cin >> m;
    for(int i=0;i<m;i++) lca();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}