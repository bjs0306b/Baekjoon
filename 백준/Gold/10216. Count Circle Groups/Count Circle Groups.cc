#include <bits/stdc++.h>
using namespace std;

struct circle{
    int x,y,r;
};

int n;
vector<circle> v;
vector<int> parent;

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    int aa = find(a), bb = find(b);
    if(aa > bb) swap(aa, bb);
    parent[aa] = bb;
}

bool is_meet(int a, int b){
    int dis1 = (v[a].x - v[b].x) * (v[a].x - v[b].x) + (v[a].y - v[b].y) * (v[a].y - v[b].y); // 중심 사이 거리의 제곱
    int dis2 = (v[a].r  + v[b].r) * (v[a].r  + v[b].r);
    return dis1 <= dis2;
}

void input(){
    cin >> n;

    parent.clear();
    parent.resize(n);
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
        cin >> v[i].x >> v[i].y >> v[i].r;
    }
}

void solve(){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(is_meet(i,j)){
                merge(i,j);
            }
        }
    }
    set<int> temp;
    for(int i=0;i<n;i++){
        int p = find(i);
        temp.insert(p);
    }
    cout << temp.size() << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        input();
        solve();
    }

    return 0;
}