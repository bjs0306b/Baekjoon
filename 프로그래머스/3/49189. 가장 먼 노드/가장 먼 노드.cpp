#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> v[n+1], dis(n+1, 0);
    vector<bool> visited(n+1, false);
    for(int i=0;i<edge.size();i++){
        int a = edge[i][0], b = edge[i][1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    int mx_dis = 0;
    queue<int> q;
    q.push(1); visited[1] = true;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int f = q.front(); q.pop();
            for(auto k : v[f]){
                if(visited[k]) continue;
                visited[k] = true;
                dis[k] = cnt;
                mx_dis = max(mx_dis, cnt);
                q.push(k);
            }
        }
        cnt++;
    }
    int ret = 0;
    for(int i=1;i<=n;i++){
        if(mx_dis == dis[i]){
            ret++;
        }
    }
    return ret;
}