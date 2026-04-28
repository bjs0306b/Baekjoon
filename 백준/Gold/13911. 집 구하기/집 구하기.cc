#include <bits/stdc++.h>
using namespace std;

int V,E, mc_limit, st_limit, M, S;
int is_not_home[10001]; // 0 = home, 1 = mc, 2 = st
vector<pair<int,int>> v[10001];
vector<int> mc_pos, st_pos, mc_dis, st_dis;
void input(){
    cin >> V >> E;
    for(int i=0;i<E;i++){
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    cin >> M >> mc_limit;
    mc_pos.resize(M); mc_dis.resize(V+1, 1000000000); for(int i=0;i<M;i++){cin >> mc_pos[i]; is_not_home[mc_pos[i]] = true;}
    cin >> S >> st_limit;
    st_pos.resize(S); st_dis.resize(V+1, 1000000000); for(int i=0;i<S;i++){cin >> st_pos[i]; is_not_home[st_pos[i]] = true;}
}

void dijkstra(vector<int>& start, vector<int>& dis, int limit){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
    
    for(auto k : start){
        pq.push({0, k}); 
        dis[k] = 0;
    }
    
    while(!pq.empty()){
        auto t = pq.top(); pq.pop();
        int cur_dis = t.first;
        int cur_node = t.second;

        if(cur_dis > dis[cur_node] || cur_dis > limit) continue;

        for(auto k : v[cur_node]){
            int cost = k.first;
            int nx_node = k.second;
            if(dis[nx_node] > dis[cur_node] + cost){
                dis[nx_node] = dis[cur_node] + cost;
                pq.push({dis[nx_node], nx_node});
            }
        }
    }
}

void solve(){
    dijkstra(mc_pos, mc_dis, mc_limit);
    dijkstra(st_pos, st_dis, st_limit);

    int ans = INT32_MAX;
    for(int i=1;i<=V;i++){
        if(is_not_home[i]) continue;
        if(mc_dis[i] > mc_limit || st_dis[i] >st_limit) continue;
        ans = min(ans, mc_dis[i] + st_dis[i]);
    }
    if(ans == INT32_MAX) cout << -1;
    else cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}