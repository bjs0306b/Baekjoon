#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> a,b, parent;

void input(){
    cin >> n >> m >> k;
    a.resize(m); parent.resize(m); 
    for(int i=0;i<m;i++){cin >> a[i]; parent[i] = i;}
    b.resize(k); for(int i=0;i<k;i++) cin >> b[i];
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    int xx = find(x), yy = find(y);
    if(xx > yy) swap(xx, yy);
    parent[xx] = yy;
}

void solve(){
    sort(a.begin(), a.end());

    for(int i=0;i<k;i++){
        auto iter = upper_bound(a.begin(), a.end(), b[i]);
        int num = iter - a.begin();

        int num_p = find(num);
        cout << a[num_p] << "\n";

        if(num_p + 1 < m) merge(num_p, num_p + 1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    input();
    solve();
    return 0;
}