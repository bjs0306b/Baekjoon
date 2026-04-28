#include <bits/stdc++.h>
using namespace std;

int n;
int A[10000][6];
int ans;

void dfs(int bottom, int depth, int sum){
    if(depth == n){
        ans = max(ans, sum);
    }
    int i;
    for(i=0;i<6;i++){
        if(A[depth][i] == bottom){
            break;
        }
    }
    if(i == 0) dfs(A[depth][5], depth + 1, sum + max(max(max(A[depth][1],A[depth][2]),A[depth][3]),A[depth][4]));
    else if(i == 1) dfs(A[depth][3], depth + 1, sum + max(max(max(A[depth][0],A[depth][2]),A[depth][5]),A[depth][4]));
    else if(i == 2) dfs(A[depth][4], depth + 1, sum + max(max(max(A[depth][1],A[depth][0]),A[depth][3]),A[depth][5]));
    else if(i == 3) dfs(A[depth][1], depth + 1, sum + max(max(max(A[depth][0],A[depth][2]),A[depth][5]),A[depth][4]));
    else if(i == 4) dfs(A[depth][2], depth + 1, sum + max(max(max(A[depth][1],A[depth][0]),A[depth][3]),A[depth][5]));
    else if(i == 5) dfs(A[depth][0], depth + 1, sum + max(max(max(A[depth][1],A[depth][2]),A[depth][3]),A[depth][4]));

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<6;j++) cin >> A[i][j];
    
    for(int i=0;i<6;i++) dfs(A[0][i], 0, 0);
    cout << ans;
    
    return 0;
}