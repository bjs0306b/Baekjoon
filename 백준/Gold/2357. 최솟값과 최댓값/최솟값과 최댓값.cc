#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v, tree_mx, tree_mn;
vector<pair<int,int>> w;

void input(){
    cin >> n >> m;
    v.resize(n);
    tree_mx.resize(4*n);
    tree_mn.resize(4*n);
    w.resize(m);
    for(int i=0;i<n;i++)
        cin >> v[i];
    for(int i=0;i<m;i++) cin >> w[i].first >> w[i].second;
}

int build_mx(int node, int s, int e){
    if(s == e) return tree_mx[node] = v[s];

    int m = (s+e)/2;

    int a = build_mx(node*2, s, m), b = build_mx(node*2+1, m+1, e);
    return tree_mx[node] = max(a,b);
}

int query_mx(int node, int s, int e, int l, int r){
    if(l > e || r < s) return 0;
    if(l <= s && e <= r) return tree_mx[node];

    int m = (s+e)/2;
    int a = query_mx(node*2, s, m, l, r), b = query_mx(node*2+1, m+1, e, l, r);

    return max(a,b);
}

int build_mn(int node, int s, int e){
    if(s == e) return tree_mn[node] = v[s];

    int m = (s+e)/2;

    int a = build_mn(node*2, s, m), b = build_mn(node*2+1, m+1, e);
    return tree_mn[node] = min(a,b);
}

int query_mn(int node, int s, int e, int l, int r){
    if(l > e || r < s) return INT32_MAX;
    if(l <= s && e <= r) return tree_mn[node];

    int m = (s+e)/2;
    int a = query_mn(node*2, s, m, l, r), b = query_mn(node*2+1, m+1, e, l, r);

    return min(a,b);
}


void solve(){
    build_mx(1, 0, n-1);
    build_mn(1, 0, n-1);
    for(int i=0;i<m;i++){
        int mx = query_mx(1, 0, n-1, w[i].first-1, w[i].second-1);
        int mn = query_mn(1, 0, n-1, w[i].first-1, w[i].second-1);
        cout << mn << " " << mx << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}