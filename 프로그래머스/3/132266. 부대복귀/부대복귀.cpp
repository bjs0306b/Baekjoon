#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> v[n+1];
    for(auto k : roads){
        int a = k[0], b = k[1];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> dis(n+1, -1);
    queue<int> q; q.push(destination); dis[destination] = 0;
    
    int cnt = 1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            int f = q.front(); q.pop();
            for(auto k : v[f]){
                if(dis[k] != -1) continue;
                dis[k] = cnt;
                q.push(k);
            }
        }
        cnt++;
    }
    vector<int> ret;
    for(auto k : sources){
        ret.push_back(dis[k]);
    }
    return ret;
}