#include <string>
#include <vector>

using namespace std;

bool visited[1<<17];
vector<int> is_wolf, v[17];
int ans, n;

void dfs(int visit, int sheep, int wolf){
    if(visited[visit]) return;
    visited[visit] = true;
    if(sheep <= wolf) return;
    ans = max(ans, sheep);
    
    for(int i=0;i<n;i++){
        if(visit & (1 << i)){ // 현재 방문한 노드에 대해서
            for(auto k : v[i]){
                if(visit & (1 << k)) continue;
                if(is_wolf[k]) dfs((visit | (1<<k)), sheep, wolf+1);
                else dfs((visit | (1<<k)), sheep+1, wolf);
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    n = info.size();
    for(auto k : edges){
        v[k[0]].push_back(k[1]);
    }
    is_wolf = info;
    dfs(1, 1, 0);
    return ans;
}