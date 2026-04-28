#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[5001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int s,t; cin >> s >> t;

    priority_queue<pair<int,int>> pq;
    pq.push({0, s});
    vector<int> dis(n+1, INT32_MAX);
    dis[s] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dis[cur] < cost) continue;

        for(int i=0;i<v[cur].size();i++){
            
            int npos = v[cur][i].first;
            int ncost = v[cur][i].second;

            if(dis[cur] + ncost < dis[npos]){
                dis[npos] = dis[cur] + ncost;
                pq.push({-dis[npos], npos});
            }
        }
    }

    cout << dis[t];

    return 0;
}