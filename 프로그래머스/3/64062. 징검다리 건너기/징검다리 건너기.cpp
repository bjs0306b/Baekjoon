#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int s = 1, e = *max_element(stones.begin(), stones.end());
    
    int ret = 0;
    while(s <= e){
        int m = (s + e) / 2;
        
        int cnt = 0;
        bool flag = true;
        for(auto stone : stones){
            if(stone < m){
                cnt++;
                if(cnt >= k){
                    flag = false;
                    break;
                }
            }
            else cnt = 0;
        }
        
        if(flag){ // 통과
            ret = m;
            s = m + 1;
        }
        else e = m-1;
    }
    
    return ret;
}