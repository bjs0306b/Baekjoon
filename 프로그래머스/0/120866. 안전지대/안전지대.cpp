#include <string>
#include <vector>

using namespace std;

int dx[] = {-1,-1,-1,0,1,1,1,0, 0}, dy[] = {-1,0,1,1,1,0,-1,-1, 0};

int solution(vector<vector<int>> board) {
    int n = board.size(), m = board[0].size();
    int ret = n*m;
    bool is_danger[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) is_danger[i][j] = false;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]){
                for(int k=0;k<9;k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && !is_danger[nx][ny]){
                        is_danger[nx][ny] = true;
                        ret--;
                    }
                }
            }
        }
    }
    return ret;
}