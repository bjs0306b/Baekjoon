#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[20001];
int dis[20001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int v,e,start; cin >> v >> e >> start;
    for(int i=0;i<e;i++){
        int a,b,w; cin >> a >> b >> w;
        vec[a].push_back({w,b});
    }
    fill(dis, dis+20001, INT32_MAX);
    dis[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    
    while(!pq.empty()){
        int cur_dis = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dis[cur_node] >= cur_dis){
            for(auto edge : vec[cur_node]){
                int weight = edge.first;
                int next_node = edge.second;

                if(dis[next_node] > dis[cur_node] + weight){
                    dis[next_node] = dis[cur_node] + weight;
                    pq.push({dis[next_node], next_node});
                }
            }
        }
    }

    for(int i=1;i<=v;i++){
        if(dis[i] == INT32_MAX) cout << "INF\n";
        else cout << dis[i] << "\n";
    }
    return 0;
}