#include <bits/stdc++.h>
using namespace std;

int n; 
int A[300][300];
bool visited[300][300];

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
            char c; cin >> c;
            if(c == '.') A[i][j] = 0;
            else A[i][j] = -1;
        }
    }
}

int dx[] = {-1,-1,-1,0,1,1,1,0}, dy[] = {-1,0,1,1,1,0,-1,-1};
void show_boom(int x, int y){
    for(int i=0;i<8;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != -1){
            A[nx][ny]++;
        }
    }
}

void touch(int x, int y){
    visited[x][y] = true;
    if(A[x][y] == 0){
        for(int i=0;i<8;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && A[nx][ny] != -1 && !visited[nx][ny]){
               touch(nx, ny);
            }
        }
    }
}

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] == -1){
                show_boom(i,j);
                visited[i][j] = true;
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[i][j] == 0 && !visited[i][j]){
                touch(i,j);
                ans++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                ans++;
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for(int i=1;i<=t;i++){
        input();
        cout << "#" << i << " ";
        solve();
    }

    return 0;
}