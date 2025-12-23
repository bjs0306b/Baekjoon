#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m; cin >> n >> m;
    int A[n][m]; for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];
    int t; cin >> t;

    int ans = 0;
    int dx[] = {-1,-1,-1,0,1,1,1,0,0}, dy[] = {-1,0,1,1,1,0,-1,-1,0};
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            vector<int> temp(9);
            for(int k=0;k<9;k++){
                temp[k] = A[i+dx[k]][j+dy[k]];
            }
            sort(temp.begin(), temp.end());
            if(temp[4] >= t) ans++;
        }
    }
    cout << ans;

    return 0;
}