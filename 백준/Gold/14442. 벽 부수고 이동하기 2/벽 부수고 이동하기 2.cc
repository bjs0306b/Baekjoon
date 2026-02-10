#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y,t;
};

int n,m,k;
bool visited[1000][1000][10], A[1000][1000];

void input(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '1') A[i][j] = true;
            else A[i][j] = false;
        }
    }
}

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int solve(){
    queue<node> q;
    q.push({0,0,k});
    visited[0][0][k] = true;

    int cnt = 1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto f = q.front(); q.pop();
            int x = f.x, y = f.y, t = f.t;
            if(x == n-1 && y == m-1) return cnt;
            for(int j=0;j<4;j++){
                int nx = x + dx[j], ny = y + dy[j];
                if(!(nx >= 0 && nx < n && ny >= 0 && ny < m)) continue;
                if(A[nx][ny]){
                    if(t>0 && !visited[nx][ny][t-1]){
                        visited[nx][ny][t-1] = true;
                        q.push({nx, ny, t-1});
                    }
                }
                else{
                    if(!visited[nx][ny][t]){
                        visited[nx][ny][t] = true;
                        q.push({nx,ny,t});
                    }
                }  
            }
        }
        cnt++;
    }

    return -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    cout << solve();

    return 0;
}