#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    
    pair<int,int> dp[1000001]; 
    for(int i=0;i<=target;i++){
        dp[i] = {1000000000, 0};
    }
    dp[0] = {0,0};
    for(int i=0;i<target;i++){
        for(int j=1;j<=20;j++){
            if(i+j <= target){ // 싱글
                if(dp[i+j].first > dp[i].first + 1){
                    dp[i+j] = {dp[i].first + 1, dp[i].second + 1}; 
                }
                else if(dp[i+j].first == dp[i].first + 1){
                    if(dp[i+j].second < dp[i].second + 1){
                        dp[i+j].second = dp[i].second + 1;
                    }
                }
            }
            if(i+2*j <= target){ // 더블
                if(dp[i+2*j].first > dp[i].first + 1){
                    dp[i+2*j] = {dp[i].first + 1, dp[i].second}; 
                }
                else if(dp[i+2*j].first == dp[i].first + 1){
                    if(dp[i+2*j].second < dp[i].second){
                        dp[i+2*j].second = dp[i].second;
                    }
                }
            }
            if(i+j <= target){ // 트리플
                if(dp[i+3*j].first > dp[i].first + 1){
                    dp[i+3*j] = {dp[i].first + 1, dp[i].second}; 
                }
                else if(dp[i+3*j].first == dp[i].first + 1){
                    if(dp[i+3*j].second < dp[i].second){
                        dp[i+3*j].second = dp[i].second;
                    }
                }
            }
        }
        if(i+50 <= target){ // 불
            if(dp[i+50].first > dp[i].first + 1){
                dp[i+50] = {dp[i].first + 1, dp[i].second + 1}; 
            }
            else if(dp[i+50].first == dp[i].first + 1){
                if(dp[i+50].second < dp[i].second + 1){
                    dp[i+50].second = dp[i].second + 1;
                }
            }
        }
    }
    
    return {dp[target].first, dp[target].second};
}