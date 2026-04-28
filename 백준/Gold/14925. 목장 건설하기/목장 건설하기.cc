#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> arr[i][j];
    int ans = 0;

    for(int i=0;i<n;i++) if(!arr[i][0]){ans = 1, dp[i][0] = 1;}
    for(int i=0;i<m;i++) if(!arr[0][i]){ans = 1, dp[0][i] = 1;}

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(!arr[i][j]){
                dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans;

    return 0;
}