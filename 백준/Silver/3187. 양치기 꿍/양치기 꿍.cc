#include <bits/stdc++.h>
using namespace std;

int total_v, total_k;
int cnt_v, cnt_k;
char A[250][250];
bool visited[250][250];
int n,m;

int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
void dfs(int x, int y){
    
    if(A[x][y] == 'v') cnt_v++; if(A[x][y] == 'k') cnt_k++;

    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(!visited[nx][ny] && !(A[nx][ny] == '#') && nx >= 0 && nx < n && ny >= 0 && ny < m){
            visited[nx][ny] = true;
            dfs(nx,ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] != '#' && !visited[i][j]){
                cnt_k = 0, cnt_v = 0;
                visited[i][j] = true;
                dfs(i,j);
                if(cnt_k > cnt_v) total_k += cnt_k;
                else total_v += cnt_v;
            }
        }
    }
    cout << total_k << " " << total_v;


    return 0;
}