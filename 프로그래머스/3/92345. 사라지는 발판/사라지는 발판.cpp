#include <string>
#include <vector>

using namespace std;

int n,m;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
vector<vector<int>> v;

pair<bool, int> dfs(pair<int,int> now, pair<int,int> next){
    if(v[now.first][now.second] == 0) return {false, 0};
    
    bool can_win = false;
    int mn = 9999, mx = 0;
    
    for(int i=0;i<4;i++){
        int nx = now.first + dx[i], ny = now.second + dy[i];
        if(!(nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == 1)) continue;
            
        v[now.first][now.second] = 0;
        
        auto res = dfs(next, {nx, ny});
        
        v[now.first][now.second]  = 1;
        
        if(!res.first){
            can_win = true;
            mn = min(mn, res.second + 1);
        }else if(!can_win){
            mx = max(mx, res.second + 1);
        }
    }
    if(can_win) return {true, mn};
    else return {false, mx};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size(), m = board[0].size();
    v = board;
    auto ret = dfs({aloc[0], aloc[1]}, {bloc[0], bloc[1]});
    return ret.second;
}