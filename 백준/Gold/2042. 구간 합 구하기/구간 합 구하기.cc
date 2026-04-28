#include <bits/stdc++.h>
using namespace std;

vector<long long> v, tree;

long long build(long long num, long long s, long long e){

    if(s == e) return tree[num] = v[s];

    long long m = (s+e)/2;
    
    long long l = build(num*2, s,m);
    long long r = build(num*2+1, m+1, e);

    return tree[num] = l + r;
}

long long query(long long num, long long s, long long e, long long l, long long r){
    if(l <= s && e <= r) return tree[num];
    if(l > e || r < s) return 0;

    long long m = (s+e)/2;
    long long ll = query(num*2, s, m, l, r);
    long long rr = query(num*2+1, m+1, e, l, r);
    return ll + rr;
}

void update(long long num, long long s, long long e, long long idx, long long diff){
    if(!(s <= idx && idx <= e)) return;

    tree[num] += diff;

    if(s == e) return;

    long long m = (s+e)/2;
    update(num*2, s, m, idx, diff);
    update(num*2+1, m+1, e, idx, diff);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long n,m,k;
    cin >> n >> m >> k;
    v.resize(n); for(long long i=0;i<n;i++) cin >> v[i];
    tree.resize(4*n);

    build(1, 0, n-1);
    
    for(long long i=0;i<m+k;i++){
        long long a,b,c; cin >> a >> b >> c;
        if(a == 1){
            update(1, 0, n-1, b-1, c - v[b-1]);
            v[b-1] = c;
        }
        else if(a==2) cout << query(1, 0, n-1, b-1, c-1) << "\n";
    }

    return 0;
}