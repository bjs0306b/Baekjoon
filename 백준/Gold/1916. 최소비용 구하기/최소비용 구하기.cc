#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec[1001]; // w, start
int dis[1001]; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b,w; cin >> a >> b >> w; // a->b, w
        vec[a].push_back({w,b});
    }
    int s,e; cin >> s >> e;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    fill(dis, dis+1001, INT32_MAX);
    dis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        int cur_dis = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dis[cur_node] >= cur_dis){
            for(auto next : vec[cur_node]){
                int weight = next.first;
                int next_node = next.second;
                if(dis[next_node] > dis[cur_node] + weight){
                    dis[next_node] = dis[cur_node] + weight;
                    pq.push({dis[next_node], next_node});
                }
            }
        }
    }
    cout << dis[e];

    return 0;
}