#include <bits/stdc++.h>
using namespace std;

int n,m;
int A[20][301], dp[20][301];

void input(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        for(int j=0;j<m;j++){
            cin >> A[j][i];
        }
    }
}

void solve(){
    for(int i=1;i<=n;i++) dp[0][i] = A[0][i];
    for(int i=1;i<m;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=n-j;k++){
                dp[i][k+j] = max(dp[i][k+j], dp[i-1][k] + A[i][j]);
            }
        }
    }

    cout << dp[m-1][n] << "\n";

    // cout << "\nA : \n";
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "dp : \n";

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << A[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    vector<int> v;
    int x = m-1, y = n;
    while(x >= 0){
        for(int i=0;i<=y;i++){
            if(dp[x][y] == dp[x-1][y-i] + A[x][i]){
                v.push_back(i);
                x--;
                y -= i;
                break;
            }
        }
    }
    for(int i=v.size()-1;i>=0;i--) cout << v[i] << " ";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();
    
    return 0;
}