#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin >> n >> m;
    int arr[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) arr[i][j] = 0;
    for(int i=1;i<=m;i++){
        int a,b,c; cin >> a >> b >> c;
        a--,b--;
        if(c == 1){
            for(int j=a;j>=0;j--) arr[j][b]++;
        }
        else if(c == 2){
           for(int j=a-1;j>=0;j--) for(int k=b+1;k<n;k++) arr[j][k]++;
        }
         else if(c == 3){
            for(int j=b;j<n;j++) arr[a][j]++;
        }
         else if(c == 4){
            for(int j=a+1;j<n;j++) for(int k=b+1;k<n;k++) arr[j][k]++;
        }
         else if(c == 5){
            for(int j=a;j<n;j++) arr[j][b]++;
        }
         else if(c == 6){
             for(int j=a+1;j<n;j++) for(int k=b-1;k>=0;k--) arr[j][k]++;
        }
         else if(c == 7){
            for(int j=b;j>=0;j--) arr[a][j]++;
        }
         else if(c == 8){
             for(int j=a-1;j>=0;j--) for(int k=b-1;k>=0;k--) arr[j][k]++;
        }
    }
    int mx = 0;
    pair<int,int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mx < arr[i][j]){
                mx = arr[i][j];
                ans = {i,j};
            }
        }
    }
    cout << ans.first+1 << " " << ans.second+1;
    return 0;
}