#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <memory.h>

using namespace std;

vector<pair<int,int>> pos[7];
bool visited[7];
vector<vector<int>> v;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int n;

int bfs(int ax, int ay, int bx, int by){
    queue<pair<int,int>> q;
    q.push({ax, ay});
    bool visited2[4][4] = {false};
    visited2[ax][ay] = true;
    int ret = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto f = q.front(); q.pop();
            if(f.first == bx && f.second == by) return ret;
            
            // 그냥 이동
            for(int j=0;j<4;j++){
                int nx = f.first + dx[j], ny = f.second + dy[j];
                if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !visited2[nx][ny]){
                    visited2[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            // ctrl 이동
            for(int j=0;j<4;j++){
                int nx = f.first, ny = f.second;
                for(int k=1;k<4;k++){
                    nx += dx[j], ny += dy[j];
                    if(!(nx >= 0 && nx < 4 && ny >= 0 && ny < 4)){
                        nx -= dx[j], ny -= dy[j];
                        break;
                    }
                    if(v[nx][ny] > 0) break;
                }
                if(visited2[nx][ny]) continue;
                visited2[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        ret++;
    }
    return 100;
}

int dfs(int x, int y, int dep){
    if(dep == n) return 0;
    int mn = 1e9;
 
    for(int i=1;i<7;i++){
        if(visited[i]) continue;
        
        auto a = pos[i][0], b = pos[i][1];
        // 현재 -> a -> b
        int dis1 = bfs(x, y, a.first, a.second) + bfs(a.first, a.second, b.first, b.second) + 2;
        // 현재 -> b -> a
        int dis2 = bfs(x, y, b.first, b.second) + bfs(b.first, b.second, a.first, a.second) + 2;
        
        visited[i] = true;
        v[a.first][a.second] = v[b.first][b.second] = 0;
        
        mn = min(mn, min(dis1 + dfs(b.first, b.second, dep+1), dis2 + dfs(a.first, a.second, dep+1)));
        
        visited[i] = false;
        v[a.first][a.second] = v[b.first][b.second] = i;
    }
   
    return mn;
}

int solution(vector<vector<int>> board, int r, int c) {
    memset(visited, true, sizeof(visited));
    n = 0;
    v = board;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]){
                pos[board[i][j]].push_back({i,j});
                visited[board[i][j]] = false;
                n++;
            }
        }
    }
    n /= 2;
    
    int ret = dfs(r, c, 0);
    return ret;
}