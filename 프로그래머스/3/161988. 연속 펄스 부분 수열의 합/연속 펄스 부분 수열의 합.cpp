#include <string>
#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

long long solution(vector<int> sequence) {
    
    long long n = sequence.size();
    long long dp[n][2]; memset(dp, 0, sizeof(dp));

    dp[0][0] = sequence[0];
    dp[0][1] = -sequence[0];
    
    long long ans = max(dp[0][0], dp[0][1]);
    
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][1] + (long long) sequence[i], (long long) sequence[i]);
        dp[i][1] = max(dp[i-1][0] - (long long) sequence[i], - (long long)sequence[i]);
        
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    
    return ans;
}