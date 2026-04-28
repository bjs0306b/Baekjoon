#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[500][500];
bool visited[500][500];

int cnt;

int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
void dfs(int x, int y){
    visited[x][y] = true;
    cnt++;
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && A[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];

    int ans1 = 0;
    int ans2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && A[i][j]){
                ans1++;
                dfs(i,j);
                ans2 = max(ans2, cnt);
                cnt = 0;
            }
        }
    }
    cout << ans1 << "\n" << ans2;

    return 0;
}