#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;
int A[100][100];
bool visited[100][100];
int cnt;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
void dfs(int x, int y){
    cnt += A[x][y];
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny] > 0){
            visited[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}

vector<int> solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maps[i][j] == 'X'){
                A[i][j] = 0;
            }
            else A[i][j] = maps[i][j] - '0';
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] || A[i][j] == 0) continue;
            visited[i][j] = true;
            cnt = 0;
            dfs(i, j);
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size()){
        return ans;
    }
    else return {-1};
}