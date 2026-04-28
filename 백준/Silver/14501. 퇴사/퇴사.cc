#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int dp[100]; memset(dp, 0, sizeof(int)*100);
    for(int i=1;i<n+1;i++){
        dp[i] = *max_element(dp, dp+i+1);
        int a,b; cin >>a>>b;
        dp[i+a-1] = max(dp[i+a-1], dp[i-1]+b);
    }
    cout << dp[n];
    
    return 0;
}