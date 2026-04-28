#include <bits/stdc++.h>
using namespace std;

bool arr[5][5];
bool visited[5][5];
int a,b,n;
int ans;

void dfs(int x, int y, int cnt){
    if(x == 0 && y == b-1){
        if(cnt == n) ans++;
    }
    else{
        int dx[4] = {0,0,-1,1}, dy[4] = {-1,1,0,0};
        for(int i=0;i<4;i++){
            if(!arr[x+dx[i]][y+dy[i]] &&!visited[x+dx[i]][y+dy[i]] && x+dx[i] >= 0 && x+dx[i] < a && y+dy[i] >= 0 && y+dy[i] < b){
                visited[x+dx[i]][y+dy[i]] = true;
                dfs(x+dx[i], y+dy[i], cnt+1);
                visited[x+dx[i]][y+dy[i]] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> n;
    for(int i=0;i<a;i++) for(int j=0;j<b;j++){char c; cin >> c; if(c == '.') arr[i][j] = 0; else arr[i][j] = 1;}
    visited[a-1][0] = true;
    dfs(a-1,0,1);

    cout << ans;

    return 0;
}