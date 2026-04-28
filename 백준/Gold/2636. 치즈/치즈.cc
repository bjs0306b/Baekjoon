#include <bits/stdc++.h>
using namespace std;

int total_before, total;
bool A[100][100];
int n,m;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){cin >> A[i][j]; if(A[i][j]) total++;}
}

int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
bool visited[100][100];

void dfs(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]){
            visited[nx][ny] = true;
            if(A[nx][ny]){total--; A[nx][ny] = false;}
            else dfs(nx, ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    int cnt = 0;
    while(total){
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j] = false;
        total_before = total;
        visited[0][0] = true;
        dfs(0,0);
        cnt++;
    }
    
    cout << cnt << "\n" << total_before;
    
    return 0;
}