#include <string>
#include <vector>

using namespace std;

vector<int> v[100001];
int dp[100001][2];

void dfs(int cur, int pre){
    dp[cur][0] = 0;
    dp[cur][1] = 1;
    
    for(auto k : v[cur]){
        if(k == pre) continue;
        
        dfs(k, cur);
        
        dp[cur][0] += dp[k][1];
        
        dp[cur][1] += min(dp[k][0], dp[k][1]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    for(int i=1;i<=n;i++) v[i].clear();
    for(auto k : lighthouse){
        v[k[0]].push_back(k[1]);
        v[k[1]].push_back(k[0]);
    }
    dfs(1, 0);
    
    return min(dp[1][0], dp[1][1]);
}