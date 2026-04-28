#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int A[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++){A[i][j] = 1000000; if(i==j) A[i][j] = 0;}
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<n;j++){
            if(s[j] == 'Y') A[i][j] = 1;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(i != j && A[i][j] <= 2){
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    
    return 0;
}