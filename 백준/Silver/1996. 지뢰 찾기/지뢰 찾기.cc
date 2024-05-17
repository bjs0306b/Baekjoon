#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    char arr[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> arr[i][j];
    char ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == '.'){
                int sum = 0;
                if(i-1 >= 0 && arr[i-1][j] != '.') sum += arr[i-1][j] - '0';
                if(j-1 >= 0 && arr[i][j-1] != '.') sum += arr[i][j-1] - '0';
                if(i+1 < n && arr[i+1][j] != '.') sum += arr[i+1][j] - '0';
                if(j+1 < n && arr[i][j+1] != '.') sum += arr[i][j+1] - '0';
                if(i-1 >= 0 && j-1 >= 0 && arr[i-1][j-1] != '.') sum += arr[i-1][j-1] - '0';
                if(i-1 >= 0 && j+1 < n && arr[i-1][j+1] != '.') sum += arr[i-1][j+1] - '0';
                if(i+1 < n && j-1 >= 0 && arr[i+1][j-1] != '.') sum += arr[i+1][j-1] - '0';
                if(i+1 < n && j+1 < n && arr[i+1][j+1] != '.') sum += arr[i+1][j+1] - '0';
                
                if(sum > 9) ans[i][j] = 'M';
                else ans[i][j] = sum + '0';
            }
            else ans[i][j] = '*';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}