#include <string>
#include <vector>

using namespace std;

int m;
vector<vector<int>> v;
bool visited[200];

void dfs(int cur){
    for(int k=0;k<m;k++){
        if(visited[k] || v[cur][k] == 0) continue;
        visited[k] = true;
        dfs(k);
    }
}

int solution(int n, vector<vector<int>> computers) {
    m = n;
    v = computers;
    int answer = 0;
    
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        visited[i] = true;
        answer++;
        dfs(i);
    }
    
    
    return answer;
}