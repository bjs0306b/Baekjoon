#include <vector>
#include <memory.h>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    // 0행, 0열에 대해서 먼저 초기화
    int dp[m][n][2]; memset(dp, 0, sizeof(dp)); // dp[i][j][0] -> 아래방향, dp[i][j][1] -> 오른쪽 방향
    for(int i=0;i<m;i++){
        if(city_map[i][0] == 1) break;
        dp[i][0][0] = 1;
    }
    for(int i=0;i<n;i++){
        if(city_map[0][i] == 1) break;
        dp[0][i][1] = 1;
    }
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(city_map[i][j] == 1) continue;
            
            if(city_map[i-1][j] == 2){
                dp[i][j][0] = dp[i-1][j][0];
            }
            else dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1])%MOD;
            
            if(city_map[i][j-1] == 2){
                dp[i][j][1] = dp[i][j-1][1];
            }
            else dp[i][j][1] = (dp[i][j-1][0] + dp[i][j-1][1])%MOD;
        }
    }
    return (dp[m-1][n-1][0] + dp[m-1][n-1][1])%MOD;
}