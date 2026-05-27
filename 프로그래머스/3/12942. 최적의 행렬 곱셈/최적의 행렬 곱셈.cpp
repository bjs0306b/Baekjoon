#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int n = matrix_sizes.size();
    int dp[n][n]; for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = INT32_MAX;
    for(int i=0;i<n;i++) dp[i][i] = 0;
    for(int i=0;i<n-1;i++){
        dp[i][i+1] = matrix_sizes[i][0] * matrix_sizes[i][1] * matrix_sizes[i+1][1];
    }
    for(int l=3;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int e = i + l - 1;
            for(int j=i;j<e;j++){
                dp[i][e] = min(dp[i][e], dp[i][j] + dp[j+1][e] + matrix_sizes[i][0]*matrix_sizes[j][1] * matrix_sizes[e][1]);
            }    
        }
    }
    return dp[0][n-1];
}