#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<int> cnt(n, 0);
    
    // 정방향
    int dis[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) dis[i][j] = 1e9;
    for(int i=0;i<n;i++) dis[i][i] = 0;
    for(auto k : results){
        dis[--k[0]][--k[1]] = 1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j && dis[i][j] != 1e9) cnt[j]++;
        }
    }
    
    // 역방향
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) dis[i][j] = 1e9;
    for(int i=0;i<n;i++) dis[i][i] = 0;
    for(auto k : results){
        dis[--k[1]][--k[0]] = 1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i != j && dis[i][j] != 1e9) cnt[j]++;
        }
    }
    
    int ret = 0;
    for(int i=0;i<n;i++) if(cnt[i] == n-1) ret++;
    return ret;
}