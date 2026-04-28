#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> m >> n;
    bool A[n][m]; int mn[n][m];
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '1') A[i][j] = true;
            else A[i][j] = false;
            mn[i][j] = INT32_MAX;
        }
    }
    mn[0][0] = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(A[nx][ny] && mn[nx][ny] - 1 > mn[x][y]){
                    mn[nx][ny] = mn[x][y] + 1;
                    q.push({nx,ny});
                }
                else if(!A[nx][ny] && mn[nx][ny] > mn[x][y]){
                    mn[nx][ny] = mn[x][y];
                    q.push({nx,ny});
                }
            }
        }
    }
    cout << mn[n-1][m-1];
    
    return 0;
}