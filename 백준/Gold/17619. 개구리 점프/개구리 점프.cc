#include <bits/stdc++.h>
using namespace std;

struct node{
    int x1, x2, y, idx;

    bool operator<(const node other) const{
        if(x1 == other.x1) return x2 < other.x2;
        return x1 < other.x1;
    }
};

int n,q;
vector<node> v;
vector<int> parent;
void input(){
    cin >> n >> q;        
    v.resize(n);
    parent.resize(n);
    for(int i=0;i<n;i++){
        int a,b,c; cin >> a >> b >> c;
        v[i] = {a,b,c,i};
        parent[i] = i;
    }                  
    sort(v.begin(), v.end());

    // for(int i=0;i<n;i++){
    //     cout << v[i].x1 << " " << v[i].x2 << "\n";
    // }
}

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    int aa = find(a), bb = find(b);
    if(aa > bb) swap(aa, bb);
    parent[aa] = bb;
}

void solve(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[j].x1 <= v[i].x2){
                // cout << i << " " <<  j << "\n";
                merge(find(v[i].idx), find(v[j].idx));
            }
            else break;
        }
    }

    for(int i=0;i<q;i++){
        int a,b; cin >> a >> b;
        a--, b--;
        if(find(a) == find(b)) cout << "1\n";
        else cout << "0\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}