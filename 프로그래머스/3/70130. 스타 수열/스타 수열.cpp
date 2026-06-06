#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    unordered_map<int, vector<int>> um;
    for(int i = 0; i < a.size(); i++){
        um[a[i]].push_back(i);
    }
    
    int ans = 0;
    for(auto k : um){
        // 가지치기: 이 숫자로 만들 수 있는 최대 길이가 현재 정답보다 작거나 같으면 건너뜀
        if (k.second.size() * 2 <= ans) continue;
        
        int pairs = 0;
        int last_used_idx = -1; // set 대신 마지막으로 사용한 인덱스를 기록
        
        vector<int> idx = k.second;
        for(auto kk : idx){
            // 1. 왼쪽 원소 확인
            // 조건: 범위 안이고, 자신과 숫자가 다르며, 이전에 사용된 적이 없어야 함
            if(kk != 0 && a[kk-1] != k.first && last_used_idx < kk-1) {
                last_used_idx = kk-1;
                pairs++;
            }
            // 2. 오른쪽 원소 확인 (왼쪽 짝짓기에 실패한 경우에만 시도)
            else if(kk != a.size()-1 && a[kk+1] != k.first && last_used_idx < kk+1) {
                last_used_idx = kk+1;
                pairs++;
            }
        }
        
        ans = max(ans, pairs * 2);
    }
    
    return ans;
}