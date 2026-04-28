#include <bits/stdc++.h>
using namespace std;

struct node{
    int n1,n2,dis;

    bool operator<(const node other) const{
        if(dis == other.dis) return n1 > other.n1;
        return dis > other.dis;
    }
};

int n, ans;
priority_queue<node> pq;
vector<int> parent;

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    int aa = find(a), bb = find(b);
    if(aa > bb) swap(aa,bb);
    parent[aa] = bb;
}


void input(){
    cin >> n;
    vector<pair<int,int>> x(n),y(n),z(n);
    parent.resize(n);
    for(int i=0;i<n;i++){
        parent[i] = i;
        int a,b,c; cin >> a >> b >> c;
        x[i] = {a, i}, y[i] = {b, i}, z[i] = {c, i};
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    // x
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            pq.push({x[i].second, x[j].second, x[j].first - x[i].first});
            if(x[i].first != x[j].first) break;
        }
    }
    // y
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            pq.push({y[i].second, y[j].second, y[j].first - y[i].first});
            if(y[i].first != y[j].first) break;
        }
    }
    // z
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            pq.push({z[i].second, z[j].second, z[j].first - z[i].first});
            if(z[i].first != z[j].first) break;
        }
    }
}

void solve(){
    int cnt = n-1;
    while(cnt){
        node t = pq.top();
        pq.pop();
        int n1 = find(t.n1), n2 = find(t.n2);
        if(n1 == n2) continue;
        cnt--;
        ans += t.dis;
        merge(n1, n2);
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}