#include <bits/stdc++.h>
using namespace std;

int n, A[500][500], mx[500][500], ans = 0;
int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};

void input(){
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[i][j];
}

int dfs(int x, int y){

    int temp = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n && A[x][y] < A[nx][ny]){
            if(mx[nx][ny]) temp = max(temp, mx[nx][ny]);
            else temp = max(temp, dfs(nx,ny));
        }
    }   

    return mx[x][y] = temp + 1;
}

void solve(){
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) ans = max(ans, dfs(i,j));
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    
    return 0;
}