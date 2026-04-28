#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v, pos, tree;

void input(){
    cin >> n >> m;
    v.clear();
    v.resize(n+m, 0);
    tree.clear();
    tree.resize(4*(n+m));
    for(int i=0;i<n;i++) v[i] = 1;

    pos.clear();
    pos.resize(n+1);
    for(int i=1;i<=n;i++) pos[i] = n - i;
}

int build(int idx, int s, int e){
    if(s == e) return tree[idx] = v[s];
    int mid = (s + e)/2;
    int ll = build(idx*2, s, mid);
    int rr = build(idx*2+1, mid+1, e);
    return tree[idx] = ll + rr;
}

void print(int idx, int s, int e){
    if(s == e){
        cout << v[s] << " ";
        return;
    }
    int mid = (s + e)/2;
    build(idx*2, s, mid);
    build(idx*2+1, mid+1, e);
}

int query(int idx, int s, int e, int l, int r){
    if(l <= s && e <= r) return tree[idx];
    if(e < l || r < s) return 0;
    int mid = (s+e)/2;
    int ll = query(idx*2, s, mid, l, r), rr = query(idx*2+1, mid+1, e, l, r);
    return ll + rr;
}

int update(int idx, int s, int e, int p, int value){
    if(s == e) return tree[idx] = v[s] = value;
    
    int mid = (s+e)/2;
    int ll, rr;
    if(s <= p && p <= mid){
        ll = update(idx*2, s, mid, p, value);
        rr = tree[idx*2+1];
    }
    else{
        ll = tree[idx*2];
        rr = update(idx*2+1, mid+1, e, p, value);
    }

    return tree[idx] = ll + rr;
}

void solve(){
    build(1, 0, n+m-1);
    //for(int i=1;i<=15;i++) cout << tree[i] << " ";
    //cout << "\n";
    for(int i=0;i<m;i++){   
        int num; cin >> num;
        cout << query(1, 0, n+m-1, pos[num]+1, n+i-1) << " ";
        update(1, 0, n+m-1, pos[num], 0);
        //for(int i=1;i<=15;i++) cout << tree[i] << " ";
        //cout << "\n";
        update(1, 0, n+m-1, n+i, 1);
        //for(int i=1;i<=15;i++) cout << tree[i] << " ";
        //cout << "\n";
        pos[num] = n+i;
    }
    cout << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    
    int t; cin >> t;
    for(int i=0;i<t;i++){
        input();
        solve();
    }
    

    return 0;
}