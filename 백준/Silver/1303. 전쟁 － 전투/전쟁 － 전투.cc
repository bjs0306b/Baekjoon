#include <bits/stdc++.h>
using namespace std;

char A[100][100];
int n,m, cnt;
bool visited[100][100];
int ans[2];

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
void dfs(int x, int y, char c){
    cnt++;
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny] == c){
            visited[nx][ny] = true;
            dfs(nx,ny, c);
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                cnt = 0;
                visited[i][j] = true;
                dfs(i,j, A[i][j]);
                
                if(A[i][j] == 'W') ans[0] += cnt*cnt;
                else ans[1] += cnt*cnt;
            }
        }
    }
    cout << ans[0] << " " << ans[1];


    return 0;
}