#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long n,m,k;
vector<long long> v, tree;

void input(){
    cin >> n >> m >> k;
    v.resize(n);
    tree.resize(4*n);
    for(long long i=0;i<n;i++) cin >> v[i];
}

long long build(long long n, long long s, long long e){
    if(s == e) return tree[n] = v[s];

    long long mid = (s+e)/2;

    long long a = build(n*2, s, mid), b = build(n*2+1, mid+1, e);

    return tree[n] = a*b%MOD;
}

long long query(long long n, long long s, long long e, long long l, long long r){
    if(e < l || r < s) return 1;
    if(l <= s && e <= r) return tree[n];

    long long mid = (s+e)/2;
    long long a = query(n*2, s, mid, l, r), b= query(n*2+1, mid+1, e, l, r);
    return a*b%MOD;
}

long long update(long long n, long long s, long long e, long long k, long long p){
    if(!(s <= k && k <= e)) return tree[n];

    if(s == e) return tree[n] = p;

    long long mid = (s+e)/2;

    long long a = update(n*2, s, mid, k, p), b = update(n*2+1, mid+1, e, k, p);

    return tree[n] = a*b%MOD;
}

void solve(){
    build(1, 0, n-1);

    for(long long i=0;i<m+k;i++){
        long long a,b,c; cin >> a >> b >> c;
        if(a == 1){
            update(1,0,n-1,b-1,c);
        }
        if(a == 2){
            cout << query(1,0,n-1,b-1,c-1) << "\n";
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}