#include <bits/stdc++.h>
using namespace std;

char A[100][100];
int n;

void input(){
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[i][j];
}

int dx[] = {-1,-1,-1,0,1,1,1,0}, dy[] = {-1,0,1,1,1,0,-1,-1};
int check(int x, int y){
    int ret = 0;
    for(int i=0;i<8;i++){
        string s = "";
        s += A[x][y];
        int nx = x, ny = y;
        for(int j=0;j<4;j++){
            nx += dx[i], ny += dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                s += A[nx][ny];
            }
            else break;
        }
        if(s == "MOBIS") ret++;
    }
    return ret;
}

void solve(){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans += check(i,j);
        }
    }
    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    input();
    solve();
    
    return 0;
}