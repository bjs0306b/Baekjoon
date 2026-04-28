#include <bits/stdc++.h>
using namespace std;

long long n, dis[5001];
vector<pair<long long,long long>> v[5001]; // 거리, 노드


void input(){
    cin >> n;
    for(long long i=0;i<n-1;i++){
        long long a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
}

void dijkstra(){
    priority_queue<pair<long long,long long>> pq; // 거리, 노드
    pq.push({0, 1});
    for(long long i=2;i<=n;i++) dis[i] = INT64_MAX;

    while(!pq.empty()){
        long long cur_dis = -pq.top().first;
        long long cur_node = pq.top().second;
        pq.pop();

        if(dis[cur_node] <  cur_dis) continue;

        for(long long i=0;i<v[cur_node].size();i++){
            long long next_dis = v[cur_node][i].first;
            long long next_node = v[cur_node][i].second;

            if(dis[next_node] > dis[cur_node] + next_dis){
                dis[next_node] = dis[cur_node] + next_dis;
                pq.push({-dis[next_node], next_node});
            }
        }
    }

    cout << *max_element(dis+2, dis+n+1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    input();
    dijkstra();

    return 0;
}