#include <bits/stdc++.h>
using namespace std;

int n,m; 
int v[15][15];
int dx1[] = {-1,0,1,0}, dy1[] = {0,1,0,-1};
int dx2[] = {-1,-1,1,1}, dy2[] = {-1,1,1,-1};
int func(int x, int y){
    int sum1 =v[x][y];
    for(int i=1;i<m;i++){
        for(int j=0;j<4;j++){
            int nx = x + i * dx1[j], ny = y + i * dy1[j];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                sum1 += v[nx][ny];
            }
        }
    }
    int sum2 =v[x][y];
    for(int i=1;i<m;i++){
        for(int j=0;j<4;j++){
            int nx = x + i * dx2[j], ny = y + i * dy2[j];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                sum2 += v[nx][ny];
            }
        }
    }
    return max(sum1, sum2);
}

void solve(){
    cin >> n >> m;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> v[i][j];
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num =  func(i,j);
            ans = max(ans, num);
        }
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    for(int i=1;i<=t;i++){
        cout << "#" << i << " ";
        solve();
    }

    return 0;
}