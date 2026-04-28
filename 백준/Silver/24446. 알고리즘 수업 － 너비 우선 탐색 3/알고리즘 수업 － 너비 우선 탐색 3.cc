#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m,r; cin >> n >> m >> r;
    vector<int> v[n+1];
    vector<int> dis(n+1, -1);
    vector<bool> visited(n+1, false);
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    visited[r] = true;
    dis[r] = 0;

    queue<int> q; q.push(r);

    int cur_dis = 1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int cur_node = q.front();
            q.pop();
            for(auto k : v[cur_node]){
                if(!visited[k]){
                    dis[k] = cur_dis;
                    q.push(k);
                    visited[k] = true;
                }
            }
        }
        cur_dis++;
    }

    for(int i=1;i<=n;i++) cout << dis[i] << "\n";

    return 0;
}