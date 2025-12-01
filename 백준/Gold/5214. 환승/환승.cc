#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,k,m;
    cin >> n >> k >> m;
    vector<int> v[m], index[n+1];
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            int num; cin >> num;
            v[i].push_back(num);
            index[num].push_back(i);
        }
    }

    vector<int> dis(n+1, INT32_MAX);
    dis[1] = 1;

    priority_queue<pair<int,int>> pq; // {거리, 노드}
    pq.push({-1, 1});

    while(!pq.empty()){
        int cur_node = pq.top().second;
        int cur_dis = -pq.top().first;
        pq.pop();

        if(dis[cur_node] < cur_dis) continue;
        
        for(int i=0;i<index[cur_node].size();i++){
            int temp = index[cur_node][i];

            for(auto k : v[temp]){
                if(k == cur_node) continue;

                if(cur_dis + 1 < dis[k]){
                    dis[k] = cur_dis + 1;
                    pq.push({-dis[k], k});
                }
            }
        }
    }

    if(dis[n] == INT32_MAX) cout << -1;
    else cout << dis[n];

    return 0;
}