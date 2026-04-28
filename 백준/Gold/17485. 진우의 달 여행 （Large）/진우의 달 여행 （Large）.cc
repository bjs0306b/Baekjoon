#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n,m; cin >> n >> m;
    // 조건문을 줄이기 위해 padding
    // p[x][y][d] : (x,y)에서 이전에 온 방향이 d일 떄 최소값. 
    // d = 0은 좌하단 방향으로, d = 1은 중간, d = 2는 우하단 방향으로 내려가는 방향.
    int A[n][m+1], dp[2][m+2][3]; 
    for(int i=0;i<n;i++){
        for(int j=0;j<m+2;j++){
            if(j > 0 && j < m+1) cin >> A[i][j];
            if(i < 2) for(int k=0;k<3;k++) dp[i][j][k] = 1000000000;
        }
    }
    for(int i=1;i<=m;i++) for(int j=0;j<3;j++) dp[0][i][j] = A[0][i];

    for(int i=1;i<n;i++){
         for(int j=1;j<=m;j++){
            for(int k=0;k<3;k++){
                dp[1][j][k] = 1000000000;
            }
        }

        for(int j=1;j<=m;j++){
            dp[1][j][0] = min(dp[1][j][0], A[i][j] + min(dp[0][j+1][1], dp[0][j+1][2]));
            dp[1][j][1] = min(dp[1][j][1], A[i][j] + min(dp[0][j][0], dp[0][j][2]));
            dp[1][j][2] = min(dp[1][j][2], A[i][j] + min(dp[0][j-1][0], dp[0][j-1][1]));
        }

        for(int j=1;j<=m;j++){
            for(int k=0;k<3;k++){
                dp[0][j][k] = dp[1][j][k];
            }
        }
    }
    int ans = 1000000000;
    for(int i=1;i<=m;i++){
        for(int j=0;j<3;j++){
            ans = min(ans, dp[1][i][j]);
        }
    }
    cout << ans;

    return 0;
}