#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, dis[1001], cost[1001], dp[1001]; dp[1] = 0;
    cin >> n;
    for(int i=1;i<n;i++) cin >> dis[i];
    for(int i=1;i<=n;i++) cin >> cost[i];
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + cost[1]*dis[i-1];
    }
    for(int j=2;j<n;j++){
        for(int i=j+1;i<=n;i++){
            dp[i] = min(dp[i], dp[i-1] + cost[j]*dis[i-1]);
        }
    }
    cout << dp[n];
    
    
    return 0;
}