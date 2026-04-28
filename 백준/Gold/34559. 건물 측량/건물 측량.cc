#include <bits/stdc++.h>
using namespace std;

int n,m, total[1000][1000];
bool A[1000][1000], visited[1000][1000];

int dx[ ] = {-1,1,0,0}, dy[] = {0,0,-1,1};
void dfs_visit(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && !A[nx][ny]){
            visited[nx][ny] = true;
            dfs_visit(nx, ny);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '1') A[i][j] = true;
            else A[i][j] = false;
        }
    }
    for(int i=0;i<n;i++){ // 방문을 못할 경우 (visited = false) = 건물
        for(int j=0;j<m;j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                visited[i][j] = true;   
                dfs_visit(i,j);
            }
        }
    }

    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            total[i][j] = total[i-1][j] + total[i][j-1] - total[i-1][j-1] + !visited[i][j];
        
    int k; cin >> k;
    while(k--){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--,y1--,x2--,y2--;
        int cnt = total[x2][y2];
        if(y1) cnt -= total[x2][y1-1];
        if(x1) cnt -= total[x1-1][y2];
        if(x1 && y1) cnt += total[x1-1][y1-1];
        
        if(cnt) cout << "No " << cnt << "\n";
        else cout << "Yes\n";
    }
    
    return 0;
}