#include<bits/stdc++.h>
using namespace std;

struct node{
    int n, cost;
    vector<int> v;

    bool operator<(const node other) const {
        if(cost == other.cost) return n > other.n;
        return cost > other.cost;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> vec[n+1];
    int m; cin >> m;
    while(m--){
        int s,e,c; cin >> s >> e >> c;
        vec[s].push_back({e,c});
    }

    int start, end; cin >> start >> end;

    int dis[n+1]; fill(dis, dis+n+1, INT32_MAX);
    dis[start] = 0;

    vector<int> temp; temp.push_back(start);
    priority_queue<node> pq;
    pq.push({start, 0, temp});


    vector<int> ans_vec;
    while(!pq.empty()){
        int cur_node = pq.top().n;
        int cur_dis = pq.top().cost;
        vector<int> cur_vec = pq.top().v;
        pq.pop();

        if(dis[cur_node] >= cur_dis){
            for(auto k : vec[cur_node]){
                int next_node = k.first;
                int weight = k.second;
                if(dis[next_node] > dis[cur_node] + weight){
                    dis[next_node] = dis[cur_node] + weight;
                    vector<int> hist = cur_vec;
                    hist.push_back(next_node);
                    if(next_node == end) ans_vec = hist;
                    pq.push({next_node, dis[next_node], hist});
                }
            }
        }
    }

    cout << dis[end] << "\n" << ans_vec.size() << "\n";
    for(auto k : ans_vec) cout << k << " ";
    
    return 0;
}