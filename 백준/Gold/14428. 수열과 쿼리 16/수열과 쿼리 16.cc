#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int,int>> v, tree;
void input(){
    cin >> n;
    v.resize(n);
    tree.resize(4*n);
    for(int i=0;i<n;i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }
    cin >> m;
}

pair<int,int> build(int n, int s, int e){
    if(s == e) return tree[n] = v[s];

    int mid = (s+e)/2;
    pair<int,int> a = build(2*n, s, mid), b = build(2*n+1, mid+1, e);
    return tree[n] = min(a,b);
}

pair<int,int> query(int n, int s, int e, int l, int r){
    if(e < l || r < s) return {INT32_MAX, INT32_MAX};
    if(l <= s && e <= r) return tree[n];

    int mid = (s+e)/2;
    pair<int,int> a = query(2*n, s, mid, l, r), b = query(2*n+1, mid+1, e, l, r);
    return min(a,b);
}

pair<int,int> update(int n, int s, int e, int pos, int rep){
    if(!(s <= pos && pos <= e)) return tree[n];
    if(s == e) return tree[n] = {rep,pos+1};

    int mid = (s+e)/2;
    pair<int,int> a = update(2*n, s, mid, pos, rep), b = update(2*n+1,mid+1,e,pos,rep);
    return tree[n] = min(a,b);
}

void solve(){
    build(1,0,n-1);

    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        if(a == 1){
            update(1, 0, n-1, b-1, c);
        }
        else if(a == 2){
            auto temp = query(1, 0, n-1, b-1, c-1);
            cout << temp.second << "\n";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}