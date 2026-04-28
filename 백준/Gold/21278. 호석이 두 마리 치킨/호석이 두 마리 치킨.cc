#include <bits/stdc++.h>
using namespace std;

int A[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i != j) A[i][j] = 1000000;
        }
    }
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        A[a][b] = 2;
        A[b][a] = 2;
    }   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                A[j][k] = min(A[j][k], A[j][i] + A[i][k]);
            }
        }
    }
    
    int mn = INT32_MAX;
    pair<int,int> ans;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int cnt = 0;
            for(int k=1;k<=n;k++){
                cnt += min(A[i][k], A[j][k]);
            }
            if(mn > cnt){
                mn = cnt;
                ans = {i,j};
            }
        }
    }
    cout << ans.first << " " << ans.second << " " << mn;
    
    return 0;
}