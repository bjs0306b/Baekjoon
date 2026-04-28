#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,n; cin >> m >> n;

    char arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    int ans[5]; for(int i=0;i<5;i++) ans[i] = 0;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<n-1;j++){
            int cnt = 0;
            if(arr[i][j] == '#' || arr[i+1][j] == '#' || arr[i][j+1] == '#' || arr[i+1][j+1] == '#') continue;

            if(arr[i][j] == 'X') cnt++;
            if(arr[i+1][j] == 'X') cnt++;
            if(arr[i][j+1] == 'X') cnt++;
            if(arr[i+1][j+1] == 'X') cnt++;

            ans[cnt]++;
        }
    }
    for(int i=0;i<5;i++) cout << ans[i] << "\n";

    
    
    return 0;
}