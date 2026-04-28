#include <bits/stdc++.h>
using namespace std;

int n,m;
int cur_x, cur_y;
int A[3000][3000];
bool visited[3000][3000];
void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin >> c;
            if(c == '2'){
                cur_x = i, cur_y = j;
            }
            A[i][j] = c - '0';
        }
    }
}

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
int solve(){
    queue<pair<int,int>> q;
    q.push({cur_x, cur_y});
    visited[cur_x][cur_y] = true;
    int cnt = 0;

    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            auto f = q.front();  
            q.pop();

            if(A[f.first][f.second] > 2) return cnt;

            for(int j=0;j<4;j++){
                int nx = f.first + dx[j], ny = f.second + dy[j];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny] != 1){
                    visited[nx][ny] = true;
                    q.push({nx,ny});
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
    int ans = solve();
    if(ans == -1) cout << "NIE";
    else{
        cout << "TAK\n" << ans;
    }

    return 0;
}