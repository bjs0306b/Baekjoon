#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        int a; cin >> a; int arr[a+1][2], dp[a+1][2];
        for(int i=0;i<2;i++) for(int j=0;j<a;j++){cin >> arr[j][i]; dp[j][i] = arr[j][i];}

        for(int i=0;i<a-1;i++){
            dp[i+1][1] = max(dp[i][0]+arr[i+1][1], dp[i+1][1]);
            dp[i+1][0] = max(dp[i][1]+arr[i+1][0], dp[i+1][0]);
            dp[i+2][1] = max(dp[i][0]+arr[i+2][1], dp[i+2][1]);
            dp[i+2][0] = max(dp[i][1]+arr[i+2][0], dp[i+2][0]);
        }
        int ans = 0;
        for(int i=0;i<a;i++){
            for(int j=0;j<2;j++){
                if(dp[i][j] > ans) ans = dp[i][j];
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}