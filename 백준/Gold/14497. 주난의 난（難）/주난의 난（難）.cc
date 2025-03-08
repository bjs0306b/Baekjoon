#include <bits/stdc++.h>
using namespace std;

bool A[300][300];
int n,m;
int c,d;


int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
bool flag;
bool visited[300][300];
void dfs(int x, int y){
    if(x == c && y == d) flag = true;
    for(int i=0;i<4;i++){
        int tx = x + dx[i], ty = y + dy[i];
        if(!visited[tx][ty] && tx >= 0 && tx < n && ty >=0 && ty < m){
            visited[tx][ty] = true;
            if(A[tx][ty]) A[tx][ty] = false;
            else dfs(tx, ty); 
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int a,b; cin >> a >> b >> c >> d;
    a--,b--,c--,d--;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch; cin >> ch;
            if(ch == '1') A[i][j] = true;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout << A[i][j] << " ";
    //     cout << '\n';
    // }

    int ans = 1;
    for(;;){
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j] = false;
        visited[a][b] = true;
        flag = false;
        dfs(a, b);
        if(flag) break;
        ans++;
    }
    cout << ans;

    return 0;
}