#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long s = 1, e = 1e18;
    
    while(s <= e){
        long long m = (s + e) / 2;
        
        long long cnt = 0;
        for(auto k : times){
            cnt += m / (long long) k;
        }
        if(cnt >= n){
            answer = m;
            e = m - 1;
        }
        else s = m + 1;
    }
    
    return answer;
}