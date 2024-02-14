#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int arr[502][502], dp[502][502];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n; memset(dp, 0, 4*501*501);
    for(int i=1;i<=n;i++) for(int j=1;j<i+1;j++) cin >> arr[i][j];
    
    dp[1][1] = arr[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<i+1;j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+arr[i+1][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + arr[i+1][j+1]); 
        }
    }
    cout << *max_element(&dp[n][1], &dp[n][n+1]);
    
    
    return 0;
}