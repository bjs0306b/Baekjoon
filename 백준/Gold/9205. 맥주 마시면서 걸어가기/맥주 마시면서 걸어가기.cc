#include <bits/stdc++.h>
using namespace std;

void func(){
    int n; cin >> n;
    vector<pair<int,int>> v(n+2), edge[n+2];
    vector<int> dis(n+2, INT32_MAX); dis[0] = 0;
    for(int i=0;i<n+2;i++) cin >> v[i].first >> v[i].second;
    
    // 간선 길이
    for(int i=0;i<n+1;i++){
        for(int j=i+1;j<n+2;j++){
            int d = abs(v[j].first - v[i].first) + abs(v[j].second - v[i].second);
            if(d > 1000) continue;
            edge[i].push_back({j,d});
            edge[j].push_back({i,d});
        }
    }
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int dist = -pq.top().first, cur = pq.top().second;
        pq.pop();

        if(dis[cur] < dist) continue;

        for(int i=0;i<edge[cur].size();i++){
            int cost = dist + edge[cur][i].second;
            if(cost < dis[edge[cur][i].first]){
                dis[edge[cur][i].first] = cost;
                pq.push({-cost, edge[cur][i].first});
            }
        }
    }
    
    if(dis[n+1] != INT32_MAX) cout << "happy\n";
    else cout << "sad\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        func();
    }
    
    return 0;
}