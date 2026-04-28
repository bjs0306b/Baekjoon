#include <bits/stdc++.h>
using namespace std;

struct node{
    double dis;
    long long n1, n2;

    bool operator<(const node other) const{
        return dis >= other.dis;
    }
};

long long n,m,cnt;
vector<pair<long long,long long>> coor;
vector<long long> parent;
priority_queue<node> pq;

long long find(long long a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(long long a, long long b){
    long long aa = find(a), bb = find(b);
    if(aa < bb) swap(aa, bb);
    parent[aa] = bb;
}

void input(){
    cin >> n >> m;
    cnt = n - 1;
    coor.resize(n);
    parent.resize(n+1);
    for(long long i=0;i<n;i++){
        parent[i] = i;
        long long a,b; cin >> a >> b;
        coor[i] = {a,b};
    }
    for(long long i=0;i<m;i++){
        long long a,b; cin >> a >> b;
        a--, b--;
        
        int aa = find(a), bb = find(b);
        if(aa == bb) continue;
        cnt--;
        merge(a, b);
    }
}

double ret_dis(long long a, long long b){
    long long dis = (coor[a].first - coor[b].first)*(coor[a].first - coor[b].first) + (coor[a].second - coor[b].second)*(coor[a].second - coor[b].second);
    double ret = sqrt(dis);
    return ret;
}

void make_dis(){
    for(long long i=0;i<n-1;i++){
        for(long long j=i+1;j<n;j++){
            double dis = ret_dis(i, j);
            pq.push({dis, i, j});
        }
    }
}

void mst(){

    double ans = 0;
    while(cnt){
        node t = pq.top(); pq.pop();
        long long aa = find(t.n1), bb = find(t.n2);
        if(aa == bb) continue;
        cnt--;
        merge(aa, bb);
        ans += t.dis;
    }
    cout << fixed << setprecision(2) << ans;
}

void solve(){
    make_dis();
    mst();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    
    input();
    solve();

    return 0;
}