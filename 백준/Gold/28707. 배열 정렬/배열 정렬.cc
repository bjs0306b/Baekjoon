#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b,c;
};

int n,m;
vector<int> v;
vector<node> w;

priority_queue<pair<int, vector<int>>> pq;
map<vector<int>, int> dis;

void input(){
    cin >> n;
    v.resize(n); for(int i=0;i<n;i++) cin >> v[i];
    cin >> m;
    w.resize(m); for(int i=0;i<m;i++) cin >> w[i].a >> w[i].b >> w[i].c;
}

void solve(){
    dis[v] = 0;
    pq.push({0, v});

    while(!pq.empty()){
        int cur_dis = -pq.top().first;
        auto cur_node = pq.top().second;
        pq.pop();

        if(dis[cur_node] < cur_dis) continue;

        for(auto k : w){
            swap(cur_node[k.a-1], cur_node[k.b-1]);

            if(dis.find(cur_node) == dis.end() || dis[cur_node] > cur_dis + k.c){
                dis[cur_node] = cur_dis + k.c;
                pq.push({-dis[cur_node], cur_node});
            }

            swap(cur_node[k.a-1], cur_node[k.b-1]);
        }
    }

    sort(v.begin(), v.end());
    if(dis.find(v) != dis.end()) cout << dis[v];
    else cout << -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}