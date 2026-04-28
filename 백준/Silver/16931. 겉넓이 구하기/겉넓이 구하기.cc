#include <bits/stdc++.h>
using namespace std;
int arr[102][102];
int ans;
int dx[4] = {-1,0,0,1}, dy[4] = {0,-1,1,0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m; ans += 2*n*m; // 위, 아래 면의 넓이이
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> arr[i][j];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                if(arr[i][j] > arr[i+dx[k]][j+dy[k]]){
                    ans += (arr[i][j] - arr[i+dx[k]][j+dy[k]]);
                }
            }
        }
    }
    cout << ans;

    return 0;
}