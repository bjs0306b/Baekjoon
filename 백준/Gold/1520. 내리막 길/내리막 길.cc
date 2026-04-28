#include <bits/stdc++.h>
using namespace std;

int arr[500][500], dp[500][500];
int n,m;

int dfs(int x, int y){
    if(x == n-1 && y == m-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[x][y] > arr[nx][ny]){
            dp[x][y] += dfs(nx, ny);
        }
    }
    return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){cin >> arr[i][j]; dp[i][j] = -1;}

    cout << dfs(0,0);

    return 0;
}