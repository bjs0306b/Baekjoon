#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
    int n = board.size();
    int m = board[0].size();
    pair<int,int> start, end;
    bool visited[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
            char c = board[i][j];
            if(c == 'R'){
                start = {i,j};
            }
            if(c == 'G'){
                end = {i,j};
            }
        }
    }
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    
    int ret = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto f = q.front();
            int cur_x = f.first, cur_y = f.second;
            // cout << ret << ": " << cur_x << " " << cur_y << "\n";
            q.pop();

            for(int j=0;j<4;j++){
                int nx = cur_x, ny = cur_y;
                while(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != 'D'){
                    nx += dx[j], ny += dy[j];
                }
                nx -= dx[j], ny -= dy[j];
                if(board[nx][ny] == 'G') return ret+1;
                
                if(visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        ret++;
    }
    return -1;
}