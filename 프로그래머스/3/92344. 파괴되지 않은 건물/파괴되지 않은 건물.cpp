#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size(), m = board[0].size();
    int dif[n+1][m+1]; memset(dif, 0, sizeof(dif));
    
    for(auto k : skill){
        int inc = k[5];
        if(k[0] == 1) inc *= -1;
        
        int r1 = k[1], c1 = k[2], r2 = k[3], c2 = k[4];
        
        dif[r1][c1] += inc;
        dif[r1][c2+1] -= inc;
        dif[r2+1][c1] -= inc;
        dif[r2+1][c2+1] += inc;
    }
    
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            dif[i][j] += dif[i][j-1];
        }
    }
    
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            dif[i][j] += dif[i-1][j];
        }
    }
    
    int ret = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] + dif[i][j] > 0) ret++;
        }
    }
    return ret;
}