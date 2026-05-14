#include <string>
#include <vector>

using namespace std;
bool visited[1<<17];
vector<int> A, v[17];
int ans = 0;

void dfs(int visit, int sheep, int wolf){
    if(visited[visit]) return;
    visited[visit] = true;
    if(sheep <= wolf) return;
    ans = max(ans, sheep);
    
    for(int i=0;i<A.size();i++){
        if(!(visit & (1 << i))) continue; // 현재 상태에서 방문한 노드만
        for(auto k : v[i]){
            if((visit & (1 << k))) continue; // 이미 방문했으면 ㄴㄴ
              
            int next_visit = visit | (1 << k);
            if(A[k]) dfs(next_visit, sheep, wolf+1);  
            else dfs(next_visit, sheep+1, wolf);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(auto k : edges){
        v[k[0]].push_back(k[1]);
    }
    A = info;
    dfs(1, 1, 0);   
    return ans;
}