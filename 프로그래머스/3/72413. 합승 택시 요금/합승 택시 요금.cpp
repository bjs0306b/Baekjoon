#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int dis[n][n]; 
    s--, a--, b--;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dis[i][j] = 1000000000;
    for(int i=0;i<n;i++) dis[i][i] = 0;
    for(int i=0;i<fares.size();i++){
        int a = fares[i][0], b = fares[i][1], c = fares[i][2];
        a--, b--;
        dis[a][b] = c;
        dis[b][a] = c;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }

    
    int ans = INT32_MAX;
    for(int i=0;i<n;i++){
        if(dis[s][i] != 1000000000 && dis[i][a] != 1000000000 && dis[i][b] != 1000000000) 
        ans = min(ans, dis[s][i] + dis[i][a] + dis[i][b]);
    }
    
    return ans;
}