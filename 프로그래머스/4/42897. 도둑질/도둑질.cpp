#include <string>
#include <vector>
#include <memory.h>
using namespace std;

int solution(vector<int> money) {
    int ret = 0;
    int n = money.size();
    
    // 맨 처음꺼 털 때
    int dp[n][2]; memset(dp, 0, sizeof(dp));
    dp[0][1] = money[0];
    for(int i=1;i<n-1;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + money[i];
    }
    dp[n-1][0] = max(dp[n-2][0], dp[n-2][1]);
    ret = max(ret, dp[n-1][0]);
    
    // 맨 처음꺼 안털 때
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i-1][0] + money[i];
    }
    ret = max(ret, max(dp[n-1][0], dp[n-1][1]));
    
    return ret;
}