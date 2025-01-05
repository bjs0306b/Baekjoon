#include <bits/stdc++.h>
using namespace std;

int ans =  0;
int n,m;

bool visited[100][70];
int A[100][70];

void dfs(int x, int y){
    int dx[8] = {-1,-1,-1,0,0,1,1,1}, dy[8] = {-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;i++){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && !visited[x+dx[i]][y+dy[i]] && A[x+dx[i]][y+dy[i]] <= A[x][y] && A[x+dx[i]][y+dy[i]] > 0){
            visited[x+dx[i]][y+dy[i]] = true;
            dfs(x+dx[i], y+dy[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];

    for(;;){
        int mx=0, mx_x, mx_y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mx < A[i][j]){
                    mx = A[i][j];
                    mx_x = i, mx_y = j;
                }
            }
        }
        if(mx==0) break;
        visited[mx_x][mx_y] = true;
        dfs(mx_x, mx_y);
        ans++;
    }
    cout << ans;

    return 0;
}