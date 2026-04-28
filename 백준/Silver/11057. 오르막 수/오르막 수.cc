#include<bits/stdc++.h>
using namespace std;
int arr[1001][10];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<10;i++) arr[1][i] = 1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                arr[i][k] += arr[i-1][j];
                arr[i][k] %= 10007;
            }
        }
    }
    for(int i=1;i<10;i++){
        arr[n][0] += arr[n][i];
        arr[n][0] %= 10007;
    }
    cout << arr[n][0];
    
    return 0;
}