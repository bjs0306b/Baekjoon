#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int n = cookie.size();
    vector<int> presum(n+1); presum[0] = 0;
    for(int i=0;i<n;i++){
        presum[i+1] = presum[i] + cookie[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int temp = presum[j] - presum[i];
            auto iter = lower_bound(presum.begin() + j + 1, presum.end(), presum[j] + temp);
            if(iter == presum.end()) continue;
            if(*iter - presum[j] == presum[j] - presum[i]){
                answer = max(answer, temp);
            }
        }
    }
    
    return answer;
}